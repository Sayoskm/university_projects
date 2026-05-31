from __future__ import annotations

import json
import re
from pathlib import Path
from typing import Any, Dict, Iterable, List, Optional


RAW_ROOT_NAME = "raw_storage"
CLEAN_ROOT_NAME = "clean_storage"


STOCK_INFO_FIELD_ALIASES = {
	"出表日期": "announce_date",
	"公司代號": "stock_code",
	"公司名稱": "stock_name",
	"公司簡稱": "short_name",
	"產業別": "industry",
}

OHLC_DAILY_FIELD_ALIASES = {
	"Date": "trade_date",
	"Code": "stock_code",
	"Name": "stock_name",
	"TradeVolume": "volume",
	"TradeValue": "turnover",
	"OpeningPrice": "open_price",
	"HighestPrice": "high_price",
	"LowestPrice": "low_price",
	"ClosingPrice": "close_price",
	"Transaction": "transaction_count",
	"Change": "price_change",
}

INSTITUTIONAL_DAILY_FIELD_ALIASES = {}

EVENT_DAILY_FIELD_ALIASES = {
	"出表日期": "announce_date",
	"發言日期": "publish_date",
	"發言時間": "announce_time",
	"公司代號": "stock_code",
	"公司名稱": "stock_name",
	"主旨": "event_title",
	"符合條款": "event_type",
	"事實發生日": "event_date",
	"說明": "event_detail",
}


def _normalize_text(value: Any) -> str: # 處理 None、全形空白、trim
	if value is None:
		return ""
	return str(value).replace("\u3000", " ").strip()

'''處理數值字串，將常見的非數字表示轉換為預設值，並移除千分位逗號'''
def _parse_int(value: Any, default: Optional[int] = None) -> Optional[int]:
	text = _normalize_text(value)
	if text in {"", "-", "－", "N/A", "na", "NA", "不適用", "無"}:
		return default
	text = text.replace(",", "")
	try:
		return int(float(text))
	except ValueError: # 非數字字串
		return default

def _parse_float(value: Any, default: Optional[float] = None) -> Optional[float]:
	text = _normalize_text(value)
	if text in {"", "-", "－", "N/A", "na", "NA", "不適用", "無"}:
		return default
	text = text.replace(",", "")
	try:
		return float(text)
	except ValueError: # 非數字字串
		return default


def _parse_date(value: Any) -> Optional[str]: # 統一日期格式為西元年
	text = _normalize_text(value)
	if not text:
		return None

	digits = re.sub(r"\D", "", text) # 移除非數字字元，\D 為非數字
	if len(digits) == 7:
		year = int(digits[:3]) + 1911
		month = digits[3:5]
		day = digits[5:7]
		return f"{year:04d}-{month}-{day}"

	if len(digits) == 8:
		year = int(digits[:4])
		month = digits[4:6]
		day = digits[6:8]
		if year < 1900:
			year += 1911
		return f"{year:04d}-{month}-{day}"

	return text


def _read_json_file(file_path: Path) -> Any:
	with file_path.open("r", encoding="utf-8") as file_handle:
		return json.load(file_handle)


def _write_json_file(file_path: Path, data: Any) -> None:
	file_path.parent.mkdir(parents=True, exist_ok=True)
	with file_path.open("w", encoding="utf-8") as file_handle:
		json.dump(data, file_handle, ensure_ascii=False, indent=4)


def _normalize_field_name(field_name: Any, aliases: Dict[str, str]) -> str:
	if not isinstance(field_name, str):
		return str(field_name)
	key = field_name.strip()
	return aliases.get(key, key)


def _clean_record_fields(raw_record: Dict[str, Any], aliases: Dict[str, str], text_fields: Optional[set[str]] = None) -> Dict[str, Any]:
	cleaned_record: Dict[str, Any] = {}
	text_field_names = text_fields or set()
	for raw_key, raw_value in raw_record.items():
		standard_key = _normalize_field_name(raw_key, aliases)
		if standard_key in text_field_names:
			cleaned_record[standard_key] = _normalize_text(raw_value).replace("\r\n", "\n")
		else:
			cleaned_record[standard_key] = _guess_and_clean_value(standard_key, raw_value)
	return cleaned_record


def _guess_and_clean_value(key: str, value: Any) -> Any:
	"""
	- Dates: fields containing '日'/'日期' or values like '1150528' → ISO date
	- Integers: fields containing '股','量','數','金額','成交','volume','Trade' → int
	- Floats/prices: fields containing '價','price','Price' → float
	- Otherwise: normalized text
	"""
	k = key.lower() if isinstance(key, str) else ""
	if k in {"announce_date", "trade_date", "event_date", "publish_date"}:
		parsed = _parse_date(value)
		return parsed if parsed is not None else _normalize_text(value)

	if isinstance(value, str) and re.search(r"日|日期|date|出表|發言日期|事實發生日", key, re.I):
		parsed = _parse_date(value)
		return parsed if parsed is not None else _normalize_text(value)


	if isinstance(value, (int, float)): # 已經是數字就直接回傳
		return value

	text = _normalize_text(value)
	if text == "":
		return text

	if k in {"volume", "transaction_count", "foreign_investor", "investment_trust", "dealer", "dealer_self_trading", "dealer_hedging", "total_net_buy_sell"} or re.search(r"股|量|數|金額|成交|volume|trade|count|buy|sell", k, re.I):
		return _parse_int(text, default=None)

	# price/float-like
	if k in {"turnover", "open_price", "high_price", "low_price", "close_price", "price_change"} or re.search(r"價|price|price|closing|opening|open|close|high|low|turnover", k, re.I):
		return _parse_float(text, default=None)

	return text


def clean_stock_info_records(raw_records: Iterable[Dict[str, Any]]) -> List[Dict[str, Any]]:

	cleaned_records: List[Dict[str, Any]] = []
	for record in raw_records:
		cleaned_records.append(_clean_record_fields(record, STOCK_INFO_FIELD_ALIASES))
	return cleaned_records


def clean_ohlc_daily_records(raw_records: Iterable[Dict[str, Any]]) -> List[Dict[str, Any]]:

	cleaned_records: List[Dict[str, Any]] = []
	for record in raw_records:
		cleaned_records.append(_clean_record_fields(record, OHLC_DAILY_FIELD_ALIASES))
	return cleaned_records


def clean_institutional_daily_records(raw_records: Iterable[Dict[str, Any]]) -> List[Dict[str, Any]]:
	cleaned_records: List[Dict[str, Any]] = []
	for record in raw_records:
		cleaned_record = _clean_record_fields(record, INSTITUTIONAL_DAILY_FIELD_ALIASES)
		if "dealer" not in cleaned_record:
			dealer_parts = []
			for dealer_key in ("dealer_self_trading", "dealer_hedging"):
				dealer_value = cleaned_record.get(dealer_key)
				if isinstance(dealer_value, (int, float)):
					dealer_parts.append(int(dealer_value))
			if dealer_parts:
				cleaned_record["dealer"] = sum(dealer_parts)
		cleaned_records.append(cleaned_record)
	return cleaned_records


def clean_event_daily_records(raw_records: Iterable[Dict[str, Any]]) -> List[Dict[str, Any]]:

	cleaned_records: List[Dict[str, Any]] = []
	for record in raw_records:
		cleaned_records.append(_clean_record_fields(record, EVENT_DAILY_FIELD_ALIASES, text_fields={"event_detail"}))
	return cleaned_records


def clean_stock_info_file(raw_file_path: Path, output_file_path: Optional[Path] = None):
	raw_records = _read_json_file(raw_file_path)
	cleaned_records = clean_stock_info_records(raw_records)
	# default output path mirrors raw under CLEAN_ROOT_NAME
	if output_file_path is None:
		output_file_path = raw_file_path.parent.parent / CLEAN_ROOT_NAME / raw_file_path.parent.name / raw_file_path.name
	_write_json_file(output_file_path, cleaned_records)


def clean_ohlc_daily_file(raw_file_path: Path, output_file_path: Optional[Path] = None):
	raw_records = _read_json_file(raw_file_path)
	cleaned_records = clean_ohlc_daily_records(raw_records)
	if output_file_path is None:
		output_file_path = raw_file_path.parent.parent / CLEAN_ROOT_NAME / raw_file_path.parent.name / raw_file_path.name
	_write_json_file(output_file_path, cleaned_records)


def clean_institutional_daily_file(raw_file_path: Path, output_file_path: Optional[Path] = None):
	raw_records = _read_json_file(raw_file_path)
	cleaned_records = clean_institutional_daily_records(raw_records)
	if output_file_path is None:
		output_file_path = raw_file_path.parent.parent / CLEAN_ROOT_NAME / raw_file_path.parent.name / raw_file_path.name
	_write_json_file(output_file_path, cleaned_records)


def clean_event_daily_file(raw_file_path: Path, output_file_path: Optional[Path] = None):
	raw_records = _read_json_file(raw_file_path)
	cleaned_records = clean_event_daily_records(raw_records)
	if output_file_path is None:
		output_file_path = raw_file_path.parent.parent / CLEAN_ROOT_NAME / raw_file_path.parent.name / raw_file_path.name
	_write_json_file(output_file_path, cleaned_records)


if __name__ == "__main__":
	# base_dir = Path(__file__).resolve().parent
	# raw_root = base_dir / RAW_ROOT_NAME
	# clean_root = base_dir / CLEAN_ROOT_NAME
    pass
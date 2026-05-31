import os
from pathlib import Path
from cleaner import clean_stock_info_file, clean_ohlc_daily_file, clean_institutional_daily_file, clean_event_daily_file


# 定義清理資料暫存根目錄（相對於本檔案）
BASE_RAW_DIR = "raw_storage"
BASE_CLEAN_DIR = "clean_storage"


def create_folders(base_clean_dir_path):
	"""在本程式中建立所需的清理資料夾（以本檔案路徑為基準）。"""
	os.makedirs(os.path.join(base_clean_dir_path, "stock_info"), exist_ok=True)
	os.makedirs(os.path.join(base_clean_dir_path, "ohlc_daily"), exist_ok=True)
	os.makedirs(os.path.join(base_clean_dir_path, "institutional_daily"), exist_ok=True)
	os.makedirs(os.path.join(base_clean_dir_path, "event_daily"), exist_ok=True)


if __name__ == "__main__":
	print("=== 啟動 TWSE 資料清理流程 ===")
	base_dir = os.path.dirname(__file__)
	raw_dir = os.path.join(base_dir, BASE_RAW_DIR)
	clean_dir = os.path.join(base_dir, BASE_CLEAN_DIR)

	create_folders(clean_dir)

	# 清理最新原始檔案（每個子資料夾取最新 *.json）
	def _latest(folder_path: Path) -> Path | None:
		p = Path(folder_path)
		files = sorted(p.glob("*.json"))
		return files[-1] if files else None

	latest = _latest(Path(raw_dir) / "stock_info")
	if latest:
		out = Path(clean_dir) / "stock_info" / latest.name
		clean_stock_info_file(latest, out)

	latest = _latest(Path(raw_dir) / "ohlc_daily")
	if latest:
		out = Path(clean_dir) / "ohlc_daily" / latest.name
		clean_ohlc_daily_file(latest, out)

	# institutional may produce summary/detail; keep call commented to avoid accidental runs
	# latest = _latest(Path(raw_dir) / "institutional_daily")
	# if latest:
	#     clean_ohlc_daily_file(latest, out)

	latest = _latest(Path(raw_dir) / "event_daily")
	if latest:
		out = Path(clean_dir) / "event_daily" / latest.name
		clean_event_daily_file(latest, out)

	print("================================================\n")
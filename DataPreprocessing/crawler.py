import os
import json
import datetime
import requests


def save_stock_info_raw(base_raw_dir="raw_storage"):
    """抓取並保存『股票基本資訊』為原始 JSON 快照"""
    today_str = datetime.datetime.now().strftime("%Y%m%d")
    file_path = os.path.join(base_raw_dir, "stock_info", f"info_{today_str}.json")

    print("【擷取】正在從證交所下載全市場股票基本資訊...")
    url = "https://openapi.twse.com.tw/v1/opendata/t187ap03_L"

    try:
        response = requests.get(url, timeout=15)
        if response.status_code == 200:
            raw_json_data = response.json()
            with open(file_path, 'w', encoding='utf-8') as f:
                json.dump(raw_json_data, f, ensure_ascii=False, indent=4)
            print(f"  => [成功] 股票基本資訊 Raw Data 已儲存至: {file_path}")
            print(f"  => [統計] 共計包含 {len(raw_json_data)} 檔公司基本面快照。")
        else:
            print(f"  => [失敗] 證交所 API 回傳錯誤碼: {response.status_code}")
    except Exception as e:
        print(f"  => [異常] 擷取基本資訊時發生錯誤: {e}")


def save_ohlc_daily_raw(base_raw_dir="raw_storage"):
    """抓取並保存『當日交易收盤行情』為原始 JSON 檔案"""
    today_str = datetime.datetime.now().strftime("%Y%m%d")
    file_path = os.path.join(base_raw_dir, "ohlc_daily", f"prices_{today_str}.json")

    print("【擷取】正在從證交所下載今日全市場收盤行情...")
    url = "https://openapi.twse.com.tw/v1/exchangeReport/STOCK_DAY_ALL"

    try:
        response = requests.get(url, timeout=15)
        if response.status_code == 200:
            raw_json_data = response.json()
            with open(file_path, 'w', encoding='utf-8') as f:
                json.dump(raw_json_data, f, ensure_ascii=False, indent=4)
            print(f"  => [成功] 每日交易資訊 Raw Data 已儲存至: {file_path}")
        else:
            print(f"  => [失敗] 證交所 API 回傳錯誤碼: {response.status_code}")
    except Exception as e:
        print(f"  => [異常] 擷取每日行情時發生錯誤: {e}")

def save_institutional_daily_raw(base_raw_dir="raw_storage"):
    """抓取並保存『當日三大法人買賣超』為原始 JSON 檔案"""
    today_str = datetime.datetime.now().strftime("%Y%m%d")
    file_path = os.path.join(base_raw_dir, "institutional_daily", f"institutional_{today_str}.json")

    print("【擷取】正在從證交所下載今日三大法人買賣超...")
    url = f"" # 證交所無開源 API 可直接抓取三大法人買賣超資料，因此僅保留函式定義與錯誤提示，實際抓取需另行實作或使用第三方資料來源

    try:
        response = requests.get(url, timeout=15)
        if response.status_code == 200:
            raw_json_data = response.json()
            with open(file_path, 'w', encoding='utf-8') as f:
                json.dump(raw_json_data, f, ensure_ascii=False, indent=4)
            print(f"  => [成功] 每日三大法人買賣超 Raw Data 已儲存至: {file_path}")
        else:
            print(f"  => [失敗] 回傳錯誤碼: {response.status_code}")
    except Exception as e:
        print(f"  => [異常] 擷取三大法人個股買賣超時發生錯誤: {e}")

def save_event_daily_raw(base_raw_dir="raw_storage"):
    """抓取並保存『重大訊息』為原始 JSON 檔案"""
    today_str = datetime.datetime.now().strftime("%Y%m%d")
    file_path = os.path.join(base_raw_dir, "event_daily", f"event_{today_str}.json")

    print("【擷取】正在從證交所下載今日重大訊息...")
    url = "https://openapi.twse.com.tw/v1/opendata/t187ap04_L"

    try:
        response = requests.get(url, timeout=15)
        if response.status_code == 200:
            raw_json_data = response.json()
            with open(file_path, 'w', encoding='utf-8') as f:
                json.dump(raw_json_data, f, ensure_ascii=False, indent=4)
            print(f"  => [成功] 每日重大訊息 Raw Data 已儲存至: {file_path}")
        else:
            print(f"  => [失敗] 證交所 API 回傳錯誤碼: {response.status_code}")
    except Exception as e:
        print(f"  => [異常] 擷取每日行情時發生錯誤: {e}")


if __name__ == "__main__":
    pass

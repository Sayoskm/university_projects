import os
from crawler import save_stock_info_raw, save_ohlc_daily_raw, save_institutional_daily_raw, save_event_daily_raw

# 定義原始資料暫存根目錄（相對於本檔案）
BASE_RAW_DIR = "raw_storage"


def create_folders(base_raw_dir_path):
    """在本程式中建立所需的資料夾（以本檔案路徑為基準）。"""
    os.makedirs(os.path.join(base_raw_dir_path, "stock_info"), exist_ok=True)
    os.makedirs(os.path.join(base_raw_dir_path, "ohlc_daily"), exist_ok=True)
    os.makedirs(os.path.join(base_raw_dir_path, "institutional_daily"), exist_ok=True)
    os.makedirs(os.path.join(base_raw_dir_path, "event_daily"), exist_ok=True)


if __name__ == "__main__":
    print("=== 啟動 TWSE 證交所 Raw Data 純暫存自動化排程 ===")
    base_dir = os.path.dirname(__file__)
    raw_dir = os.path.join(base_dir, BASE_RAW_DIR)

    create_folders(raw_dir)

    # 抓取並儲存原始檔案
    save_stock_info_raw(raw_dir)      # 保存基本資料 (JSON 格式)
    save_ohlc_daily_raw(raw_dir)      # 保存交易資料 (JSON 格式)
    # save_institutional_daily_raw(raw_dir)  # 保存三大法人買賣超 (JSON 格式)
    save_event_daily_raw(raw_dir)     # 保存重大訊息 (JSON 格式)

    print("================================================\n")
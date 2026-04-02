# Moving Average & K/D Crossover Strategies

## Overview

This is a **Python trading strategy module** designed for backtesting, demonstrating **moving average crossovers** and **K/D stochastic signals**.

Main features:

* **SmaCross Strategy** – Uses three moving averages (long, medium, short) plus RSI for entry signals:

  * Buy when short > medium > long and RSI in 50–85
  * Sell when long > medium > short and RSI in 15–50
* **KDCross Strategy** – Uses stochastic K/D indicators for entries:

  * Buy when K crosses above D (with 1% stop loss)
  * Sell when D crosses above K

---

## Usage

1. Import the strategies into your backtesting framework.
2. Assign historical OHLC data to `self.data`.
3. Initialize strategies using `init()`.
4. Call `next()` for each bar to generate buy/sell signals.
5. Backtest results will show trade entries and exits.

---

## Features

* **Multi-Timeframe Analysis** – Short, medium, and long moving averages for trend detection.
* **Stochastic Optimization** – K/D cross provides precise timing signals.
* **Risk Management** – Optional stop-loss in KDCross strategy.
* **RSI Filter** – Reduces false signals in SmaCross strategy.

---

## Note
- TA assistance was provided for sections other than the strategy.
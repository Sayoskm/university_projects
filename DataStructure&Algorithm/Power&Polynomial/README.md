# Power & Polynomial

## Overview

This is a **C++/CLI WinForms application** that demonstrates different algorithms for **exponentiation** and **polynomial evaluation**, with a simple GUI to compare performance.

---

## Usage

1. Open the solution `Bn1.sln` in Visual Studio (supports CLR).
2. Enter values for `x`, `n`, and number of repetitions `k`.
3. Check the desired algorithm(s).
4. Click **Exponation** or **Polynomial** to see results and CPU time.

---

## Features

* **Algorithm Comparison** – Measure CPU time for different methods.
* **GUI Interface** – TabControl displays results for easy comparison.
* **Polynomial Optimization** – Horner’s Rule reduces computation time for large polynomials.

* Compute `x^n` using:

  * `pow(x, n)`
  * for-loop multiplication
  * square-and-multiply method
  * optimized square-and-multiply with bit-shifting

* Evaluate polynomials `f(k)` using:

  * naive method (term-by-term)
  * Horner’s Rule for efficiency

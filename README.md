# Dual Number Automatic Differentiation Engine

A lightweight, zero-dependency, header-only **Automatic Differentiation (AutoDiff)** engine implemented in modern C++. This engine utilizes **Dual Numbers** to compute exact, machine-precision derivatives of arbitrary mathematical functions simultaneously with their evaluation, entirely bypassing the limitations of symbolic math or noisy numerical approximations.

---

## How It Works

Instead of using standard numerical approximations like finite differences (which suffer from floating-point truncation errors), this engine leverages hyper-real arithmetic using **Dual Numbers**:

$$x + \epsilon \cdot dx$$

Where $\epsilon$ is a nilpotent mathematical symbol defined by the property:

$$\epsilon^2 = 0 \quad (\epsilon \neq 0)$$

When we evaluate a function $f(x + \epsilon \cdot dx)$ using its Taylor series expansion:

$$f(x + \epsilon \cdot dx) = f(x) + f'(x)\epsilon \cdot dx + \frac{f''(x)}{2!}(\epsilon \cdot dx)^2 + \dots$$

Because $\epsilon^2 = 0$, all higher-order terms vanish instantly, leaving exactly:

$$f(x + \epsilon \cdot dx) = f(x) + f'(x)\epsilon \cdot dx$$

By overloading standard C++ operators and transcendental functions using the mathematical Chain Rule and Product Rule, the compiler tracks sensitivities automatically across complex computational graphs.

---

## Features

- **Header-Only Design:** Drop `Dual.hpp` into any project with zero configuration.
- **Compile-Time Polymorphism:** Functions written using templates (`template <typename T>`) can seamlessly evaluate standard `double` types or track derivatives using `Dual`.
- **Mathematical Operators Implemented:** Full support for custom overloaded `+`, `-`, `*`, `/`, `sin`, `cos`, and `exp`.

---

## Getting Started

### Prerequisites
A modern C++ compiler supporting C++11 or higher (e.g., `g++`, `clang++`).

### Compilation & Execution
Clone the repository and compile using optimization flags (`-O3` for high performance):

```bash
g++ E_derviation.cpp -O3 -o autodiff_engine
./autodiff_engine

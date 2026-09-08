# Numerical Approximations of Euler's Number

A C++ command-line program comparing eight numerical constructions of Euler's number $e$, created for AMS 595: Fundamentals of Computing in Fall 2020.

## Implemented methods

The menu-driven program includes:

1. compound-interest limit;
2. an improved compound-interest expansion;
3. complementary addition;
4. a power-ratio construction;
5. an approximation based on Stirling’s formula;
6. the reciprocal-factorial power series;
7. a continued fraction; and
8. a Pippenger product.

For each selected method, the program prints the approximation and its absolute error relative to the standard library value.

## Repository contents

- `e_computing.cpp` — complete C++ implementation
- `main.pdf` — final report comparing the methods

## Numerical limitations

Several methods compute factorials or integer powers using fixed-width `int` values. The program therefore restricts some inputs, and larger values can overflow before being converted to floating point. This repository preserves the original educational implementation; it is not an arbitrary-precision numerical library.

## Author

Kai Li.

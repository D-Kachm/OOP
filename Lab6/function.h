#ifndef FUNCTION_H
#define FUNCTION_H

#include <functional>

// Метод бісекції (дихотомії)
double bisection(std::function<double(double)> f, double a, double b, double eps);

// Метод Ньютона (дотичних)
double newton(std::function<double(double)> f, std::function<double(double)> df, double x0, double eps);

#endif

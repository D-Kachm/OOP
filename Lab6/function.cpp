#include "function.h"
#include <cmath>

// Метод бісекції
double bisection(std::function<double(double)> f, double a, double b, double eps) {
    double c;
    while ((b - a) / 2 > eps) {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2;
}

// Метод Ньютона
double newton(std::function<double(double)> f, std::function<double(double)> df, double x0, double eps) {
    double x = x0;
    while (std::abs(f(x)) > eps) {
        x = x - f(x) / df(x);
    }
    return x;
}

#include "function.h"
#include <cmath>

// Реалізація f(x)
double MyFunction::f(double x) {
    return x + sqrt(x) + cbrt(x) - 2.5;
}

// Реалізація f'(x)
double MyFunction::df(double x) {
    return 1 + 0.5 / sqrt(x) + 1.0 / (3 * cbrt(x * x));
}

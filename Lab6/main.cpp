#include <iostream>
#include <functional>
#include <cmath>
#include "function.h"

using namespace std;

int main() {
    // Лямбда для f(x)
    auto f = [](double x) {
        return x + sqrt(x) + cbrt(x) - 2.5;
    };

    // Лямбда для f'(x)
    auto df = [](double x) {
        return 1 + 0.5 / sqrt(x) + 1.0 / (3 * cbrt(x * x));
    };

    double a = 0.4, b = 1.0, eps = 1e-6;
    double x0 = 1.0;

    // Виклик методу бісекції
    double root_bis = bisection(f, a, b, eps);
    cout << "Root found using Bisection Method: " << root_bis << endl;

    // Виклик методу Ньютона
    double root_newton = newton(f, df, x0, eps);
    cout << "Root found using Newton's Method: " << root_newton << endl;

    return 0;
}

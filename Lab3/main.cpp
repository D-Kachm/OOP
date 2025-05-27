#include <iostream>
#include <cmath>
#include "function.h"

using namespace std;

// Метод дихотомії (бісекції)
double bisection(MyFunction func, double a, double b, double eps) {
    double c;
    while ((b - a) / 2 > eps) {
        c = (a + b) / 2;
        if (func.f(c) == 0.0)
            break;
        if (func.f(a) * func.f(c) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2;
}

// Метод Ньютона (дотичних)
double newton(MyFunction func, double x0, double eps) {
    double x = x0;
    while (abs(func.f(x)) > eps) {
        x = x - func.f(x) / func.df(x);
    }
    return x;
}

int main() {
    MyFunction f;  // Об'єкт класу з функцією

    double a = 0.4, b = 1.0, eps = 1e-6;
    double x0 = 1.0;

    // Метод дихотомії
    double root_bis = bisection(f, a, b, eps);
    cout << "Root found using Bisection Method: " << root_bis << endl;

    // Метод Ньютона
    double root_newton = newton(f, x0, eps);
    cout << "Root found using Newton's Method: " << root_newton << endl;

    return 0;
}

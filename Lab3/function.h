#ifndef FUNCTION_H
#define FUNCTION_H

// Клас функції f(x) і її похідної f'(x)
class MyFunction {
public:
    double f(double x);   // f(x) = x + sqrt(x) + cbrt(x) - 2.5
    double df(double x);  // f'(x)
};

#endif

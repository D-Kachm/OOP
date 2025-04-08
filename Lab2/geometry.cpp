#include "geometry.h"
#include <cmath>

const double EPS = 1e-9;

double crossProduct(const Point& A, const Point& B, const Point& C) {
    double x1 = B.x - A.x;
    double y1 = B.y - A.y;
    double x2 = C.x - A.x;
    double y2 = C.y - A.y;
    return x1 * y2 - y1 * x2;
}

bool isDegenerateTriangle(const Point& A, const Point& B, const Point& C) {
    return std::abs(crossProduct(A, B, C)) < EPS;
}

int pointInTriangle(const Point& A, const Point& B, const Point& C, const Point& P) {
    double d1 = crossProduct(A, B, P);
    double d2 = crossProduct(B, C, P);
    double d3 = crossProduct(C, A, P);

    bool has_neg = (d1 < -EPS) || (d2 < -EPS) || (d3 < -EPS);
    bool has_pos = (d1 > EPS) || (d2 > EPS) || (d3 > EPS);

    if (!has_neg && !has_pos)
        return 1; // On the edge
    if (!has_neg || !has_pos)
        return 2; // Inside
    return 0; // Outside
}

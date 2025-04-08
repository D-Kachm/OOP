#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Point {
    double x, y;
};

bool isDegenerateTriangle(const Point& A, const Point& B, const Point& C);
int pointInTriangle(const Point& A, const Point& B, const Point& C, const Point& P);

#endif

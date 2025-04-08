#include <iostream>
#include "geometry.h"

int main() {
    Point A, B, C;
    std::cout << "Enter coordinates of the triangle (Ax Ay Bx By Cx Cy): ";
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    if (isDegenerateTriangle(A, B, C)) {
        std::cout << "The triangle is degenerate (its area is zero).\n";
        return 1;
    }

    int n;
    std::cout << "Enter number of points to check: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Point P;
        std::cout << "Enter coordinates of point " << i + 1 << " (x y): ";
        std::cin >> P.x >> P.y;

        int result = pointInTriangle(A, B, C, P);

        std::cout << "Point (" << P.x << ", " << P.y << ") is ";
        if (result == 2)
            std::cout << "inside the triangle.\n";
        else if (result == 1)
            std::cout << "on the edge of the triangle.\n";
        else
            std::cout << "outside the triangle.\n";
    }

    return 0;
}

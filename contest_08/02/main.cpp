#include <iostream>

class Vector;

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    void move(Vector vector);
};

class Vector {
public:
    int x, y;
    Vector(Point start, Point end) {
        x = end.x - start.x;
        y = end.y - start.y;
    }
};

void Point::move(Vector vector) {
        x += vector.x;
        y += vector.y;
}

int main(){
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    Point p(x1, y1);
    Vector dir(Point(x2, y2), Point(x3, y3));
    p.move(dir);
    
    std::cout << p.x << ' ' << p.y;
}

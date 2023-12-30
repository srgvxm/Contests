#include <iostream>
#include <vector>

#include <cmath>

class Shape {
public:
    virtual double getPerimeter() {
        return 0;
    }
};

class Rectangle : public Shape {
private:
    int a, b;
public:
    Rectangle(int a, int b) : a(a), b(b) {}
    double getPerimeter() override {
        return 2 * (a + b);
    }
};

class Circle : public Shape {
private:
    int r;
public:
    Circle(int r) : r(r) {}
    double getPerimeter() override {
        return 2 * M_PI * r;
    }
};

class Triangle : public Shape {
private:
    int a, b, c;
public:
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {}
    double getPerimeter() override {
        if (a + b + c > 2 * std::max(c, std::max(a, b))) {
            return a + b + c;
        }
        else {
            return 0;
        }
    }
};

int main(){
    int momentum;
    std::cin >> momentum;
    srand(momentum);
    std::vector <Shape*> shapes(rand() % 100 + 1);
    for (int i=0; i < shapes.size(); i++){
        int a = rand()%10 + 1, b = rand()%10 + 1, c = rand()%10 + 1;
        if (rand() % 3 == 0) shapes[i] = new Rectangle(a, b);
        else if (rand() % 3 == 1) shapes[i] = new Circle(c);
        else shapes[i] = new Triangle(a, b, c);
    }
    
    double sum = 0;
    for (auto shape : shapes) { sum += shape->getPerimeter();}
    std::cout << (int)sum;
}

#include <iostream>
#include <string>

#include <algorithm>
#include <complex.h>

class Complex {
private:
    double re, im;;
public:
    Complex(double re, double im) : re(re), im(im) {}

    Complex(std::string input) {
        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        std::stringstream st(input);
        std::string im_str;
        st >> re;
        st >> im_str;
        im = std::stod(im_str);
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Complex& num){
        out << (num.re == 0.0 ? 0.0 : num.re)
            << (num.im < 0 ? "":"+")
            << (num.im == 0.0 ? 0.0 : num.im) << 'j';
        return out;
    }
    
    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator*(const Complex& other) const {
        double newReal = re * other.re - im * other.im;
        double newImag = re * other.im + im * other.re;
        return Complex(newReal, newImag);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.re * other.re + other.im * other.im;
        double newReal = (re * other.re + im * other.im) / denom;
        double newImag = (im * other.re - re * other.im) / denom;
        return Complex(newReal, newImag);
    }
};

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2(num);
    
    std::cout << c1+c2 << '\n' << c1-c2 << '\n'
              << c1*c2 << '\n' << c1/c2 << std::endl;
}

#include <iostream>

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

#include <string>
#include <algorithm>

Complex make_complex(std::string str) {
    int k = 0;
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    for (int i = 0;i < str.length();i++) {
        if ((i == 0) && (str[i] == '-')) {
            continue;
        }
        if ((str[i] == '-') || (str[i] == '+')) {
            k = i;
            break;
        }
    }
    Complex res{ std::stod(str.substr(0, k)),std::stod(str.substr(k, 100)) };
    return res;
}

void print(Complex a) {
    if (a.im == -0 && a.re == -0) {
        std::cout << "0+0j" << '\n';
    }
    else if (a.im == -0) {
        std::cout << a.re << '+' << 0 << 'j' << '\n';
    }
    else if (a.re == -0) {
        std::cout << 0 << '+' << a.im << 'j' << '\n';
    }
    else if (a.im > 0) {
        std::cout << a.re << '+' << a.im << 'j' << '\n';
    }
    else {
        std::cout << a.re << a.im << 'j' << '\n';
    }
}

Complex sum(Complex a, Complex b) {
    Complex res{ a.re + b.re,a.im + b.im };
    return res;
}

Complex sub(Complex a, Complex b) {
    Complex res{ a.re - b.re,a.im - b.im };
    return res;
}

Complex mul(Complex a, Complex b) {
    Complex res{ a.re * b.re - a.im * b.im,a.im * b.re + a.re * b.im };
    return res;
}

Complex div(Complex a, Complex b) {
    Complex res{ (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im),(a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im) };
    return res;
}

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}

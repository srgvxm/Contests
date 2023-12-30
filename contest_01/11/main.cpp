#include <iostream>
int main() {
    int A,B,C;
    std::cin>>A>>B>>C;
    if (abs(B-A)<abs(C-A)) {
        std::cout<<"B "<<abs(B-A);
    }
    else {
        std::cout<<"C "<<abs(C-A);
    }
}
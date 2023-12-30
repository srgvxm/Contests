#include <iostream>

bool is_prime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}

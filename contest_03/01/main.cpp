#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n, m;
    std::cin >> n;
    std::vector<long long> ai(n);
    for (auto& line : ai) {
        std::cin >> line;
    }
    std::cin >> m;
    std::vector<long long> bi(m);
    for (auto& line : bi) {
        std::cin >> line;
    }

    for (auto i : bi) {
        ai.push_back(i);
    }
    std::sort(ai.begin(), ai.end());
    for (auto& line : ai) {
        std::cout << line << ' ';
    }
}
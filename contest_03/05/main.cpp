#include <iostream>
#include <string>
#include <map>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main()
{
    int count;
    std::cin >> count;
    int maxs = 0;
    std::map<std::string, int> maps;
    for (int i = 0;i < count;i++) {
        std::string line;
        std::cin >> line;
        maps[line] += 1;
    }
    for (auto& a : maps) {
        maxs = max(maxs, a.second);
    }
    for (auto& a : maps) {
        if (maxs == a.second) {
            std::cout << a.first << ' ';
        }
    }
}
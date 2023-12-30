#include <iostream>
#include <string>
#include <map>

int main() {
    int n, m;
    std::cin >> n;
    std::map<std::string, std::string> maps;
    for (int i = 0; i < n; i++) {
        std::string line;
        std::cin >> line;
        int end = line.find(';', 0);
        maps[line.substr(0, end)] = line.substr(end + 1, 1000);
    }
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::string line;
        std::cin >> line;
        std::cout << maps[line] << ' ';
    }
}
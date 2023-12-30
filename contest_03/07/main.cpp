#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

int main() {
    std::string target;
    std::cin >> target;
    std::map<std::string, int> maps;
    std::vector<std::string> arr;
    std::ifstream file("data.txt"); 
    for (int i = 0; true; i++) {
        std::string str;
        file >> str;
        if (str == "stopword") {
            break;
        }
        arr.push_back(str);
    }
    for (int i = 0;i < arr.size() - 1;i++) {
        if (arr[i] == target) {
            maps[arr[i + 1]] += 1;
        }
    }
    int maxs_f = -1;
    int maxs_s = -1;
    int maxs_t = -1;
    for (auto i : maps) {
        if (i.second > maxs_f) {
            maxs_t = maxs_s;
            maxs_s = maxs_f;
            maxs_f = i.second;
        }
        else if (i.second > maxs_s) {
            maxs_t = maxs_s;
            maxs_s = i.second;
        }
        else if (i.second > maxs_t) {
            maxs_t = i.second;
        }
    }
    if (maps.empty()) {
        std::cout << '-';
    }
    for (auto i : maps) {
        if (i.second == maxs_f) {
            std::cout << i.first << ' ';
            maps.erase(i.first);
            break;
        }
    }
    for (auto i : maps) {
        if (i.second == maxs_s) {
            std::cout << i.first << ' ';
            maps.erase(i.first);
            break;
        }
    }
    for (auto i : maps) {
        if (i.second == maxs_t) {
            std::cout << i.first << ' ';
            maps.erase(i.first);
            break;
        }
    }
}
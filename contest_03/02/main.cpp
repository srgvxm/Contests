#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool f(char a, char b) {
    if (a == '(' and b != ')') {
        return false;
    }
    if (a == '[' and b != ']') {
        return false;
    }
    if (a == '{' and b != '}') {
        return false;
    }
    return true;
}

bool f1(std::string a) {
    std::vector<char> b;
    for (auto i : a) {
        if (i == '(' or i == '[' or i == '{') {
            b.push_back(i);
        }
        if (i == ')' or i == ']' or i == '}') {
            if (b.empty()) {
                return false;
            }
            else if (f(b[b.size() - 1], i)) {
                b.pop_back();
            }
            else {
                return false;
            }
        }
        if (i == '!') {
            break;
        }
    }
    return true;
}

int main() {
    std::string line;
    getline(std::cin, line);
    std::cout << (f1(line) ? "YES" : "NO");
}
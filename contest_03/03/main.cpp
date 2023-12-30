#include <iostream>
#include <string>
#include <vector>

int prior(char c) {
    if (c == '(') {
        return 0;
    }
    if (c == '+' or c == '-') {
        return 1;
    }
    if (c == '*' or c == '/' or c == '%') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
}
int main() {
    std::string line;
    std::vector<char> stack;
    getline(std::cin, line);
    line += " ";
    bool f_f = false;
    bool f_s = false;
    for (int i = 0; i < size(line) - 1; i++) {
        if (line[i] <= '9' and line[i] >= '0') {
            std::cout << line[i];
            if (line[i + 1] <= '9' and line[i + 1] >= '0') {
                continue;
            }
            else {
                std::cout << ' ';
            }
        }
        else if (line[i] != ' ') {
            if (stack.empty() or line[i] == '(' or line[i] == '^') {
                stack.push_back(line[i]);
            }
            else if (line[i] == ')') {
                while (stack.empty() == false) {
                    if (stack[stack.size() - 1] == '(') {
                        break;
                    }
                    std::cout << stack[stack.size() - 1] << ' ';
                    stack.pop_back();
                }
                stack.pop_back();
            }
            else {
                for (int j = stack.size() - 1;j >= 0;j--) {
                    if (stack.empty()) {
                        break;
                    }
                    if (stack[j] == '(') {
                        break;
                    }
                    if (prior(line[i]) <= prior(stack[j])) {
                        std::cout << stack[j] << ' ';
                        stack.pop_back();
                    }
                }
                stack.push_back(line[i]);
            }
        }
    }
    while (stack.empty() == false) {
        std::cout << stack[stack.size() - 1] << ' ';
        stack.pop_back();
    }
}
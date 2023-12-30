#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

int main()
{
    int n, m;
    std::cin >> n;
    std::set<std::string> first;
    for (int i = 0;i < n;i++) {
        std::string buf;
        std::cin >> buf;
        first.insert(buf);
    }
    int n_;
    std::cin >> n_;
    std::set<std::string> second;
    for (int i = 0;i < n;i++) {
        std::string buf;
        std::cin >> buf;
        second.insert(buf);
    }

    std::vector<std::string> res;
    for (auto i : second)res.push_back(i);
    for (auto i : first)res.push_back(i);

    std::sort(res.begin(), res.end());
    bool f = true;
    for (int i = 0;i < res.size() - 1;i++) {
        if (res[i] == res[i + 1]) {
            f = false;
            std::cout << res[i] << ' ';
        }
    }
    if (f) std::cout << -1;

}
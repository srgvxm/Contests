#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string a,b;
    std::cin>>a>>b;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    if(a==b) {
        std::cout<<"YES";
    } else {
        std::cout<<"NO";
    }
}
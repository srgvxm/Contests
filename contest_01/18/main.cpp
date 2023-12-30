#include <iostream>
#include <string>
#include <algorithm>
int main() {
    int n;
    char l;
    std::cin>>n;
    std::string header;
    while (n!=0) {
        n-=1; 
        l=(n%26)+65;
        n/=26;
        header.push_back(l);
    }
    std::reverse(header.begin(), header.end());
    std::cout<<header;
}
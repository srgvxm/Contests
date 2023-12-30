#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main() {
    std::vector<std::string> wordsSt;
    std::string wordIn;
    int flag=1, len=0;
    while (flag==1) {
        std::cin>>wordIn;
        wordsSt.push_back(wordIn);
        len++;
        if (wordIn=="end") { 
            flag=0; 
        }
    }
    std::set<std::string> wordsFn;
    for (int i=0; i<len; i++) {
        if (std::count(wordsSt.begin(), wordsSt.end(), wordsSt[i])>1) {
            wordsFn.insert(wordsSt[i]);
        }
    }
    for (auto i=wordsFn.begin(); i!=wordsFn.end(); i++) {
        std::cout<<*i<<" ";
    }
}
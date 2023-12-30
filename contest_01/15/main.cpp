#include <iostream>
#include <string>
int main() {
    std::string input;
    std::cin>>input;
    input.push_back('\n');
    char last;
    int cnt=1;
    for(int i=1; i<input.length(); i++) {
        last=input[i];
            if(input[i-1]==last) {
                cnt++;
            }
            else if(input[i-1]!=last||last=='\n') {
                cnt==1?std::cout<<input[i-1]:std::cout<<input[i-1]<<cnt;
                cnt=1;
            }
         
    }
}
#include <iostream>
#include <cmath>
int main() {
    unsigned int N;
    std::cin>>N;
    unsigned int cnt=0;
    unsigned int symb=1;
    unsigned int peak=1;
    bool Flag=false;
    while(cnt<N){
        for (int i=0; i<symb; i++) {
        	if (cnt<N) {
                cnt++;
                std::cout<<cnt;
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
        if(symb==1) {Flag=true; peak++;}
        if(symb==peak) {Flag=false;}
        Flag?symb++:symb--; 
    }
}

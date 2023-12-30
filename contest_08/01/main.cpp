#include <iostream>

class Keeper{
    int trash;
    int secret;
    
public:
    Keeper(){
        std::cin >> secret;
    }
};

int hack_it(Keeper& keeper){
    void* voidPtr = static_cast<void*>(&keeper);
    int* intPtr = static_cast<int*>(voidPtr);
    return *(intPtr + 1);
}
int main(){
    Keeper keeper;
    int secret= hack_it(keeper);
    std::cout << secret;
}

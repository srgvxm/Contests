#include <iostream>

#include <algorithm>

class IntSharedPointer {
    int* data;
    int* counter;

public:
    IntSharedPointer(int* data) : data(data), counter(new int(1)) {}

    ~IntSharedPointer() {
        --(*counter);
        if (*counter == 0) {
            delete data;
            delete counter;
        }
    }

    IntSharedPointer(const IntSharedPointer& other) : data(other.data), counter(other.counter) {
        ++(*counter);
    }

    IntSharedPointer& operator=(IntSharedPointer other) {
        std::swap(data, other.data);
        std::swap(counter, other.counter);
        return *this;
    }

    int& operator*() {
        return *data;
    }
};

void print(IntSharedPointer p){
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p){
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main(){
    IntSharedPointer p(new int);
    std::cin >> *p;
    p = p;
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);
    
    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);
    
    p = p2;
    try{
        print_with_exception(p);
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}

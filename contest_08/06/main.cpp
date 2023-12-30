#include <iostream>
#include <string>
#include <vector>

class Any{
    enum class Type{
        INT,
        DOUBLE,
        STRING,
        VECTOR_ANY_PTR
    };

    void* data;
    Type type;

public:
    Any(int* data);
    Any(double* data);
    Any(std::string* data);
    Any(std::vector<Any*>* data);
    ~Any();
    
    operator int();
    operator double();
    operator std::string();
    operator std::vector<Any*>*();

    friend std::ostream& operator<<(std::ostream& out, const Any& val);
};

std::ostream& operator<<(std::ostream& out, const Any& o);

int main(){
    Any data(new std::vector<Any*>());
    
    std::vector<Any*>* array = (std::vector<Any*>*)data;
    
    int ints_count;
    std::cin >> ints_count;
    for(int i=0; i<ints_count; i++){
        int value;
        std::cin >> value;
        Any* temp = new Any(new int(value));
        array->push_back(temp);
    }
    
    int doubles_count;
    std::cin >> doubles_count;
    for(int i=0; i<doubles_count; i++){
        double value;
        std::cin >> value;
        Any* temp = new Any(new double(value));
        array->push_back(temp);
    }

    int strings_count;
    std::cin >> strings_count;
    for(int i=0; i<strings_count; i++){
        std::string value;
        std::cin >> value;
        Any* temp = new Any(new std::string(value));
        array->push_back(temp);
    }
    
    int i = 0; double d = 0; std::string s = "";
    for(auto value: *array){
        try{ i += (int)(*value); }
        catch(...){ }
        
        try{ d += (double)(*value); }
        catch(...){ }
        
        try{ s += (std::string)(*value); }
        catch(...){ }
    }
    
    Any ai(new int(i));
    Any ad(new double(d));
    Any as(new std::string(s));
    
    std::cout << data << "\n" << ai << ' ' << ad <<  ' ' << as;
}

Any::Any(int* data) : data(data), type(Type::INT) {}
Any::Any(double* data) : data(data), type(Type::DOUBLE) {}
Any::Any(std::string* data) : data(data), type(Type::STRING) {}
Any::Any(std::vector<Any*>* data) : data(data), type(Type::VECTOR_ANY_PTR) {}

Any::~Any() {
    switch (type) {
        case Type::INT: delete static_cast<int*>(data); break;
        case Type::DOUBLE: delete static_cast<double*>(data); break;
        case Type::STRING: delete static_cast<std::string*>(data); break;
        case Type::VECTOR_ANY_PTR: 
            for(auto ptr : *static_cast<std::vector<Any*>*>(data))
                delete ptr;
            delete static_cast<std::vector<Any*>*>(data);
            break;
    }
}

Any::operator int() {
    if (type != Type::INT) throw "";
    return *static_cast<int*>(data);
}

Any::operator double() {
    if (type != Type::DOUBLE) throw "";
    return *static_cast<double*>(data);
}

Any::operator std::string() {
    if (type != Type::STRING) throw "";
    return *static_cast<std::string*>(data);
}

Any::operator std::vector<Any*> *() {
    if (type != Type::VECTOR_ANY_PTR) throw "";
    return static_cast<std::vector<Any*>*>(data);
}

std::ostream& operator<<(std::ostream& out, const Any& o) {
    switch (o.type) {
        case Any::Type::INT: return out << *static_cast<int*>(o.data);
        case Any::Type::DOUBLE: return out << *static_cast<double*>(o.data);
        case Any::Type::STRING: return out << *static_cast<std::string*>(o.data);
        case Any::Type::VECTOR_ANY_PTR: 
            for(auto ptr : *static_cast<std::vector<Any*>*>(o.data))
                out << *ptr << ' ';
            return out;
    }
    return out;
}

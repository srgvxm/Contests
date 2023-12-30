#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

void print(std::vector<Student> a) {
    if (a.empty()) { std::cout << "Empty list!"; }
    else {
        std::cout << a[0].group << '\n';
        for (int i = 0;i < size(a);i++) {
            std::cout << "- " << a[i].name << '\n';
            if (i == size(a) - 1) {
                break;
            }
            if (a[i].group != a[i + 1].group) std::cout << a[i + 1].group << '\n';
        }
    }
}
Student make_student(std::string a) {
    int end = a.find(';', 0);
    Student res{ a.substr(0,end),a.substr(end+1,1000) };
    return res;
}
bool is_upper(Student a, Student b) {
    if (a.group == b.group) {
        std::vector<std::string> c{ a.name,b.name };
        std::sort(c.begin(), c.end());
        if (c[0] == b.name) {
            return false;
        }
        return true;
    }
    else {
        std::vector<std::string> c{ a.group,b.group };
        std::sort(c.begin(), c.end());
        if (c[0] == b.group){
            return false;
        }
        return true;
    }
}

int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline
    
    std::vector<Student> students(count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::sort(students.begin(), students.end(), is_upper);
    
    print(students);
}

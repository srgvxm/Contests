#include<iostream>
#include<string>
#include<map>

std::map<std::string, double> bonuses;

#include<cmath>

class Employee {
protected:
    std::string name;
    std::string position;
    int salary;

public:
    Employee(std::string name, std::string position, int salary) : \
    name(name), position(position), salary(salary) {}

    virtual int bonus(double percent) const { 
        return round(salary * percent);
    }

    virtual int totalSalary() const{
        return salary + bonus(bonuses[position]);
    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << employee.name << " (" << employee.position << "): " << employee.totalSalary();
        return os;
    }
};

class Manager : public Employee {
public:
    Manager(std::string name, int salary = 16242) : \
    Employee(name, "manager", salary) {}

    int bonus(double percent) const { 
        if (percent < 0.1) {
            percent = 0.1;
        }
        return round(salary * percent);
    }
};

class Boss: public Employee{
public:
    Boss(std::string name, int money = 16242)
    :Employee(name, "boss", money){
    }
};

int main(){
    double boss_bonus, manager_bonus;
    std::cin >> boss_bonus >> manager_bonus;
    bonuses["manager"] = manager_bonus;
    bonuses["boss"] = boss_bonus;

    int john_money, bob_money, alice_money;
    std::cin >> john_money >> bob_money >> alice_money;
    Boss john("John", john_money);
    Manager bob("Bob", bob_money);
    Manager alice("Alice", alice_money);

    std::cout << john << '\n' << bob << '\n' << alice << std::endl;
}

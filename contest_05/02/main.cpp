#include <iostream>
#include <deque>

class Water {
    int temperature;
public:
    Water(int initialTemperature) {
        temperature = initialTemperature;
    }
    int getTemperature() const {
        return temperature;
    }
    void increaseTemperature(int degrees) {
        temperature += degrees;
    }
};
class Teapot {
    Water& water;
public:
    Teapot(Water& initialWater) : water(initialWater) {}
    bool is_boiling() const {
        return water.getTemperature() >= 100;
    }
    void heat_up(int degrees) {
        water.increaseTemperature(degrees);
    }
};

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for(auto& t : heat) std::cin >> t;
    
    Water water(temperature);
    Teapot teapot(water);
    
    while(not teapot.is_boiling()){
        teapot.heat_up(heat.front());
        heat.pop_front();
    }
    
    for(auto t : heat) std::cout << t << ' ';
}

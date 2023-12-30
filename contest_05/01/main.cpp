class Cat {
private:
    bool alive;
public:
    Cat(bool state) {
        alive = state;
    }

    bool is_alive() {
        return alive;
    }
};

class Box {
public:
    Cat open() {
        bool state = rand() % 2; 
        return Cat(state);
    }
};
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() const = 0;
    virtual void move() const = 0;

    virtual ~Animal() {}
};

class Lion : public Animal {
public:
    void makeSound() const override {
        cout << "Lion: Roar!" << endl;
    }

    void move() const override {
        cout << "Lion: Runs swiftly." << endl;
    }
};

class Fish : public Animal {
public:
    void makeSound() const override {
        cout << "Fish: Blub!" << endl;
    }

    void move() const override {
        cout << "Fish: Swims gracefully." << endl;
    }
};

int main() {
    Animal* animals[2];

    animals[0] = new Lion();
    animals[1] = new Fish();

    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
        animals[i]->move();
    }

    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }

}

/*
Lion: Roar!
Lion: Runs swiftly.
Fish: Blub!
Fish: Swims gracefully.
*/
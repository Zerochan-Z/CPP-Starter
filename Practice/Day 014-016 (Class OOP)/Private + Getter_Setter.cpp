#include <iostream>
#include <string>
using namespace std;

class Car {
private: 
    string brand;
    int speed;

public:
    Car (string b, int s) { brand = b ; speed = s; };

    // Getter - read data
    string getBrand() {
        return brand;
    }

    int getSpeed() {
        return speed;
    }

    // Setter - changes data with validation
    void setSpeed(int s) {
        if (s >= 0 && s <= 200) {
            speed = s;
        } else cout << "Invalid speed! Must be 0 - 200.\n";
    }
};

int main() {
    Car car1("Toyota", 100);

    cout << "Brand: " << car1.getBrand() << endl;
    cout << "Speed: " << car1.getSpeed() << endl;

    car1.setSpeed(150);
    cout << "New speed: " << car1.getSpeed() << endl;

    car1.setSpeed(300);
    return 0;
}
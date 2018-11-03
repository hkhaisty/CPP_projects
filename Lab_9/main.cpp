#include <iostream>

using namespace std;
int current_year = 2017;
const double PI = 3.14159;

class container {
public:
    int percent_loaded;

    container() {
        cout << " Calling container default constructor." << endl;
    }
};

class box : public container {
public:
    double height, width, length;

    box() {
        cout << " Calling box default constructor." << endl;
    }

    double volume() {
        return height * length * width;
    }
};

class cylinder : public container {
public:
    cylinder() {}

    cylinder(double rad, double len) {
        radius = rad;
        length = len;
    }

    double radius, length;

    double volume() { return PI * radius * radius * length; }
};

class rail_car {
public:
    int year_built;

    rail_car() {
        cout << " Calling rail_car default constructor." << endl;
    }

    int age() { return current_year - year_built; }
};

class box_car : public rail_car, public box {
public:
    box_car() {
        cout << " Calling box_car default constructor." << endl;
        height = 10.0;
        length = 40.0;
        width = 9.0;
    }
};

class tank_car : public rail_car, public cylinder {
public:
    tank_car() : cylinder(3.5, 40.0) {}
};

class engine : public rail_car {
public:
    engine() {}
};

class caboose : public rail_car {
public:
    caboose() {}
};

rail_car *train[100];

int main() {
    int car_count, type_code;

    cout
            << "Enter type of train car:  \n0: Engine \n1: Box Car \n2: Tank Car \n3: Caboose \n4: Remove Car \n5: Add Car \n6: Exit"
            << endl;

    for (car_count = 0; cin >> type_code; ++car_count) {

        if (type_code == 0) {
            train[car_count] = new engine;
        } else if (type_code == 1) {
            train[car_count] = new box_car;
        } else if (type_code == 2) {
            train[car_count] = new tank_car;
        } else if (type_code == 3) {
            train[car_count] = new caboose;
        } else if (type_code == 4) {
            car_count-=2;
        } else if (type_code == 5) {
            car_count++;
        } else if (type_code == 6) {
            break;
        }
        cout
                << "Enter type of train car:  \n0: Engine \n1: Box Car \n2: Tank Car \n3: Caboose \n4: Remove Car \n5: Add Car \n6: Exit"
                << endl;
    }

    cout << "There are " << car_count << " cars in the train." << endl;
}


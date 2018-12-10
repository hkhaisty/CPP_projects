using namespace std;
int current_year = 2017;
const double PI = 3.14159;

class container {
public:
    int percent_loaded;

    container() {}//cout << " Calling container default constructor." << endl;}
};

//Syntax:
//class subclass_name : public superclass_name { };
class box : public container {
public:
    double height, width, length;

    box() {}//cout << " Calling box default constructor." << endl;}
    double volume() { return height * length * width; }
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

    rail_car() {}//cout << " Calling rail_car default constructor." << endl;}
    int age() { return current_year - year_built; }
};


class box_car : public rail_car, public box {
public:
    box_car() {
        //cout << " Calling box_car default constructor." << endl;
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

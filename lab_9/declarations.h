using namespace std;

class container {
public:
    container() {}
};

class box : public container {
public:

    box() {}
};

class rail_car {
public:
    rail_car() {}
};

class tank_car : public rail_car {
public:
    tank_car() {}
};

class box_car : public rail_car, public box {
public:
    box_car() {
    }
};

class engine : public rail_car {
public:
    engine() {}
};

class caboose : public rail_car {
public:
    caboose() {}
};



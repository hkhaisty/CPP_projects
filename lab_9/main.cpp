#include <iostream>
#include "declarations.h"

const int MAX_SIZE = 100;
rail_car *train[MAX_SIZE];

int car_count;

int interpret_ar(string input);

int interpret_trains(string input);

int interpret_fb(string input);

bool add_to_front_of_train();

void take_off_front_of_train();

bool add_to_back_of_train();

void take_off_back_of_train();

void shift_array_to_right();

void shift_array_to_left();


int main() {
    string input;
    car_count = 0;
    bool loop;
    do {
        if (car_count == 0) {
            loop = add_to_back_of_train();
            cout << "There are " << car_count << " cars in the array."
                 << endl;
        } else {
            cout << "Type 'add' to add a car, 'remove' to remove a car, or 'exit' to exit" << endl;
            cin >> input;
            switch (interpret_ar(input)) {
                //this removes car from array
                case 1:
                    //if there is only one car, this removes it from the train
                    if (car_count == 1) {
                        //function call to remove car
                        take_off_back_of_train();
                        //prints out result after function call
                        cout << "There are " << car_count << " cars in the array." << endl;
                    } else {
                        //if there is more than one car in the array, prompt user to pick front or back
                        cout << "Would you like to remove a car at the front or back? (e to exit)" << endl;
                        //accept user input
                        cin >> input;
                        //switch statement to determine whether front or back should be taken off
                        switch (interpret_fb(input)) { //option menu
                            case 0:
                                //removes car from front of train
                                take_off_front_of_train();
                                //prints result of removing car
                                cout << "There are " << car_count << " cars in the array." << endl;
                                //break so we don't continue running through cases
                                break;
                            case 1:
                                //removes car from back of train
                                take_off_back_of_train();
                                //prints result of removing car
                                cout << "There are " << car_count << " cars in the array." << endl;
                                //break
                                break;
                            case -1:
                                //breaks if input is invalid
                                loop = false;
                                break;
                            default:
                                cout << "Invalid input. " << endl;
                        }
                        break;
                        case 0:
                            //prompt user to add trains to front
                            cout << "type 'front' to add a car to the front of your train "
                                    "\ntype 'back' to add a car to the back of the train"
                                    "\ntype 'exit' to exit" << endl;
                        cin >> input;
                        switch (interpret_fb(input)) { //option menu
                            case 0:
                                add_to_front_of_train();
                                cout << "There are " << car_count << " cars in the array." << endl;
                                break;
                            case 1:
                                add_to_back_of_train();
                                cout << "There are " << car_count << " cars in the array." << endl;
                                break;
                            case -1:
                                loop = false;
                                break; //exit
                            default:
                                cout << "Invalid input. " << endl;
                        }
                        break;
                        case -1:
                            loop = false;
                        break; //exit
                        default:
                            cout << "Invalid input. " << endl;
                    }
            }
        }
    } while (loop); //loops till exit requested
    // ??
    cout << "There are " << car_count << " cars in the array." << endl; //outputs final number of cars

    return 0; //added this
}

//implementation of functions
int interpret_ar(string input) { //interprets input for add/remove
    if (input == "add") return 0;
    else if (input == "remove") return 1;
    else if (input == "exit") return -1;
    else return 2;
}

int interpret_trains(string input) { //interprets input for car picking
    if (input == "engine") return 0;
    else if (input == "box") return 1;
    else if (input == "tank") return 2;
    else if (input == "caboose") return 3;
    else if (input == "exit") return -1;
    else if (input == "help") return -2;
    else return 4;
}

int interpret_fb(string input) { //interprets input for front/back
    if (input == "front") return 0;
    else if (input == "back") return 1;
    else if (input == "exit") return -1;
    else return 2;
}

bool add_to_back_of_train() { //adds car to back
    cout << "What type of rail car would you like to add?"
            "\ntype 'engine' to add an engine car"
            "\ntype 'box' to add a box car"
            "\ntype 'caboose' to add a caboose car"
            "\ntype 'tank' to add a tank car\n"
            "('exit' to exit, 'help' for help)" << endl;
    string input;
    cin >> input;
    switch (interpret_trains(input)) {
        case 0:
            train[car_count++] = new engine;
            break;
        case 1:
            train[car_count++] = new box_car;
            break;
        case 2:
            train[car_count++] = new tank_car;
            break;
        case 3:
            train[car_count++] = new caboose;
            break;
        case -1:
            return false;
        case -2:
            cout << "Options: engine, box, tank, caboose" << endl;
            break;
        default:
            cout << "Invalid input. " << endl;
            break;
    }
    return true;
}

bool add_to_front_of_train() { //adds car to back
    cout << "What type of rail car would you like to add?"
            "\ntype 'Engine' to add an engine car"
            "\ntype 'Box' to add a box car"
            "\ntype 'Caboose' to add a caboose car"
            "\ntype 'Tank' to add a tank car"
            "\n('exit' to exit, 'help' for help)" << endl;
    string input;
    cin >> input;
    switch (interpret_trains(input)) {
        case 0:
            shift_array_to_right();
            train[0] = new engine;
            car_count++;
            break;
        case 1:
            shift_array_to_right();
            train[0] = new box_car;
            car_count++;
            break;
        case 2:
            shift_array_to_right();
            train[0] = new tank_car;
            car_count++;
            break;
        case 3:
            shift_array_to_right();
            train[0] = new caboose;
            car_count++;
            break;
        case -1:
            return false;
        case -2:
            cout << "Options: engine, box, tank, caboose" << endl;
            break;
        default:
            cout << "Invalid input. " << endl;
            break;
    }
    return true;
}

void take_off_front_of_train() { //removes car from front
    delete train[0];
    shift_array_to_left;
    --car_count;
}

void take_off_back_of_train() { //removes car from back
    delete train[--car_count];
}

void shift_array_to_right() { //shifts array right for removal
    if (car_count == MAX_SIZE) cout << "Maximum car limit reached." << endl;
    else {
        for (int i = car_count - 1; i >= 0; i--) {
            train[i + 1] = train[i];
        }
    }
}

void shift_array_to_left() { //shift array left for removal
    for (int i = 0; i < car_count - 1; i++) {
        train[i] = train[i + 1];
    }
}
#include <iostream>
#include "declarations.h"

const int MAX_SIZE = 100;
rail_car *train[MAX_SIZE];

int car_count;

int interpret_ar(string input);
int interpret_trains(string input);
int interpret_fb(string input);
bool addToBack();
bool addToFront();
void removeFromBack();
void removeFromFront();
void shiftArrayRight();
void shiftArrayLeft();


int main() {
    string input;
    car_count = 0;
    bool loop;
    do {
        if (car_count == 0) {
            loop = addToBack();
            cout << "There are " << car_count << " cars in the array."
                 << endl; //adds car top array when no cars in array
        } else {
            cout << "Type 'add' to add a car, 'remove' to remove a car, or 'e' to exit" << endl;
            cin >> input;
            switch (interpret_ar(input)) {
                case 1: //removing
                    if (car_count == 1) { //best wayu to remove when there is only one car
                        removeFromBack();
                        cout << "There are " << car_count << " cars in the array." << endl;
                    } else { //removing cars when more than 1
                        cout << "Would you like to remove a car at the front or back? (e to exit)" << endl;
                        cin >> input;
                        switch (interpret_fb(input)) { //option menu
                            case 0:
                                removeFromFront();
                                cout << "There are " << car_count << " cars in the array." << endl;
                                break;
                            case 1:
                                removeFromBack();
                                cout << "There are " << car_count << " cars in the array." << endl;
                                break;
                            case -1:
                                loop = false;
                                break; //exit
                            default:
                                cout << "Invalid input. " << endl;
                        }
                        break;
                        case 0: //adding
                            cout << "type 'front' to add a car to the front of your train "
                                    "\ntype 'back' to add a car to the back of the train"
                                    "\ntype 'e' to exit" << endl;
                        cin >> input;
                        switch (interpret_fb(input)) { //option menu
                            case 0:
                                addToFront();
                                cout << "There are " << car_count << " cars in the array." << endl;
                                break;
                            case 1:
                                addToBack();
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
    else if (input == "e") return -1;
    else return 2;
}

int interpret_trains(string input) { //interprets input for car picking
    if (input == "engine") return 0;
    else if (input == "box") return 1;
    else if (input == "tank") return 2;
    else if (input == "caboose") return 3;
    else if (input == "e") return -1;
    else if (input == "h") return -2;
    else return 4;
}

int interpret_fb(string input) { //interprets input for front/back
    if (input == "front") return 0;
    else if (input == "back") return 1;
    else if (input == "e") return -1;
    else return 2;
}

bool addToBack() { //adds car to back
    cout << "What type of rail car would you like to add?"
            "\ntype 'engine' to add an engine car"
            "\ntype 'box' to add a box car"
            "\ntype 'caboose' to add a caboose car"
            "\ntype 'tank' to add a tank car\n"
            "(e to exit, h for help)" << endl;
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

bool addToFront() { //adds car to back
    cout << "What type of rail car would you like to add?"
            "\ntype 'Engine' to add an engine car"
            "\ntype 'Box' to add a box car"
            "\ntype 'Caboose' to add a caboose car"
            "\ntype 'Tank' to add a tank car"
            "\n(e to exit, h for help)" << endl;
    string input;
    cin >> input;
    switch (interpret_trains(input)) {
        case 0:
            shiftArrayRight();
            train[0] = new engine;
            car_count++;
            break;
        case 1:
            shiftArrayRight();
            train[0] = new box_car;
            car_count++;
            break;
        case 2:
            shiftArrayRight();
            train[0] = new tank_car;
            car_count++;
            break;
        case 3:
            shiftArrayRight();
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

void removeFromFront() { //removes car from front
    delete train[0];
    shiftArrayLeft;
    --car_count;
}

void removeFromBack() { //removes car from back
    delete train[--car_count];
}

void shiftArrayRight() { //shifts array right for removal
    if (car_count == MAX_SIZE) cout << "Maximum car limit reached." << endl;
    else {
        for (int i = car_count - 1; i >= 0; i--) {
            train[i + 1] = train[i];
        }
    }
}

void shiftArrayLeft() { //shift array left for removal
    for (int i = 0; i < car_count - 1; i++) {
        train[i] = train[i + 1];
    }
}
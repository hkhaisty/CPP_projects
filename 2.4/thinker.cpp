#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <cstring>
#include "thinker.h"

using namespace std;

void thinking_cap::slots(char new_green[], char new_red[]) {
    assert(strlen(new_green) < 50);
    assert(strlen(new_red) < 50);
    strcpy(green_string, new_green);
    strcpy(red_string, new_red);
}

void thinking_cap::push_green()
        {
                cout << green_string << endl;
        };
void thinking_cap::push_red()
        {
                cout << red_string << endl;
        };

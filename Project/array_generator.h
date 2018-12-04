//
// Created by harri on 11/15/2018.
//



#include <cstdlib>
#include "main.cpp"

const int array_size1 = 20;
int array_1[array_size1];

const int array_size2 = 1000;
int array_2[array_size2];

const int array_size3 = 100000;
int array_3[array_size3];

static void random_array_1() {
    for (int i = 0; i < array_size1; i++) {
        array_1[i] = rand();
    }
}

void random_array_2() {
    for (int i = 0; i < array_size2; i++) {
        array_1[i] = rand();
    }
}

void random_array_3() {
    for (int i = 0; i < array_size3; i++) {
        array_1[i] = rand();
    }
}

#endif //PROJECT_ARRAY_GENERATOR_H

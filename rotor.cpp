#include <iostream>
#include "rotor.h"

Rotor::Rotor(const char letters[]){
    for (int i = 0; i < 26; i++){
        map[i] = letters[i];
    }
}

char Rotor::transform(char c){
    int x = c - 97;
    c = map[x];
    std::cout << c;
    return c;
}


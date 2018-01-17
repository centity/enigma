#include <iostream>
#include "rotor.h"

Rotor::Rotor(char letters[], int start){
    for (int i = 0; i < 26; i++){
        map[i] = letters[i];
    }

    offset = start;
}

char Rotor::transform(char letter){
    int offset26 = *offset % 26;
    int x = letter + offset26 - 'a';
    letter = map[x];
    return letter;
}

void Rotor::rotate(){
    offset ++;
}


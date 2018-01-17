#include <iostream>
#include "rotor.h"

Rotor::Rotor(char letters[], int *offsetPtr){
    for (int i = 0; i < 26; i++){
        map[i] = letters[i];
    }

    offset = offsetPtr;
}

char Rotor::transform(char letter){
    int offset26 = *offset % 26;
    int x = letter + offset26 - 97;
    letter = map[x];
    return letter;
}


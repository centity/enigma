#include "reflector.h"

Reflector::Reflector(char letters[]) {
    for (int i = 0; i < 26; i++){
        map[i] = letters[i];
    }
}

char Reflector::transform(char letter){
    int x = letter - 97;
    letter = map[x];
    return letter;
}

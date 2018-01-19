#include "transformer.h"

// Constructor initialises private member map
Transformer::Transformer(const char letters[]) {
    for (int i = 0; i < 26; i++)
        map[i] = letters[i];
}

// Converts a char to int which accesses an element in an array
char Transformer::transform(char letter, int offset){
    return map[(letter - 'a' + offset)  % 26];
}

char Transformer::rTransform(char letter, int offset){
    int i;

    // Creates reverse map on the fly from map and a given offset
    for (i = 0; i < 26; i++)
        if (map[(i + offset) % 26] == letter)
            break;

    return 'a' + i;
}



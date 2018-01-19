#include "transformer.h"

Transformer::Transformer(const char letters[]) {
    for (int i = 0; i < 26; i++)
        map[i] = letters[i];
}

char Transformer::transform(char letter, int offset){
    return map[(letter - 'a' + offset)  % 26];
}

char Transformer::rTransform(char letter, int offset){
    int i;

    // Dynamically creates reverse mapping based on given offset
    for (i = 0; i < 26; i++)
        if (map[(i + offset) % 26] == letter)
            break;

    return 'a' + i;
}



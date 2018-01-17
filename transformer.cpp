#include "transformer.h"

Transformer::Transformer(const char letters[], const char rLetters[]) {
    for (int i = 0; i < 26; i++){
        map[i] = letters[i];
        rMap[i] = rLetters[i];
    }
}

Transformer::transform(char letter, int offset){
    return map[(letter + offset)  % 26];
}

Transformer::rTransform(char letter, int offset){
    return rMap[(letter + offset)  % 26];
}

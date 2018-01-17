#include "transformer.h"

Transformer::Transformer(const char letters[]) {
    for (int i = 0; i < 26; i++){
        map[i] = letters[i];
        rMap[letters[i] - 'a'] = i + 'a';
    }
}

char Transformer::transform(char letter, int offset){
    return map[(letter - 'a' + offset)  % 26];
}

char Transformer::rTransform(char letter, int offset){
    return rMap[(letter - 'a' + offset)  % 26];
}


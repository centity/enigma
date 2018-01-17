#include "transformer.h"

Transformer::Transformer(const char letters[], ) {
    for (int i = 0; i < 26; i++){
        map[i] = letters[i];
    }
}

Transformer::transform(char c, int offset){
    return map[c + offset  % 26];
}



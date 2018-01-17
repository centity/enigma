#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "transformer.h"

class Reflector : public Transformer {
public:
    Reflector(char letters[]);
    char transform(char letter);

private:
    char map[26];
};

#endif // REFLECTOR_H

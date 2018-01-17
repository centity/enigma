#ifndef ROTOR_H
#define ROTOR_H

#include "transformer.h"

class Rotor : public Transformer {
public:
    Rotor(char letters[], int *offsetPtr);
    char transform(char c);

private:
    char map[26];
    int *offset;
};

#endif // ROTOR_H

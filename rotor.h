#ifndef ROTOR_H
#define ROTOR_H

#include "transformer.h"

class Rotor : public Transformer {
public:
    Rotor(char letters[], int start);
    char transform(char letter);
    void rotate();
private:
    char map[26];
    int offset;
};

#endif // ROTOR_H

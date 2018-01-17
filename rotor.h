#ifndef ROTOR_H
#define ROTOR_H

#include "transformer.h"

class Rotor : public Transformer {
public:
    Rotor(const char letters[], int start);
    char transform(char letter);
    char rTransform(char letter);
    void rotate();

private:
    int offset;
};

#endif // ROTOR_H

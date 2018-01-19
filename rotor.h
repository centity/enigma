#ifndef ROTOR_H
#define ROTOR_H

#include "transformer.h"

class Rotor : public Transformer {
public:
    Rotor(const char letters[], char notchLetter, int startPosition);
    char transform(char letter);
    char rTransform(char letter);
    void rotate();
    bool isNotched();

private:
    const int notch;
    int offset;
};

#endif // ROTOR_H

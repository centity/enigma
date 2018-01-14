#ifndef ROTOR_H
#define ROTOR_H

#include "transformer.h"

class Rotor : public Transformer {
public:
    Rotor(const char letters[]);
    char transform(char c);

private:
    char map[26];
};

#endif // ROTOR_H

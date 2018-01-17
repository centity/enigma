#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "transformer.h"


class Plugboard : public Transformer {
public:
    Plugboard(const char letters[], const char rLetters[]);
    char transform(char letter);
    char rTransform(char letter);
};

#endif // PLUGBOARD_H

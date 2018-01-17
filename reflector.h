#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "transformer.h"

class Reflector : public Transformer {
public:
    Reflector(const char letters[]);
    char transform(char letter);
};

#endif // REFLECTOR_H

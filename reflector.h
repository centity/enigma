#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "transformer.h"

class Reflector : public Transformer {
public:
    // Reflector has no rTransform since it has no reverse behaviour
    Reflector(const char letters[]);
    char transform(char letter);
};

#endif // REFLECTOR_H

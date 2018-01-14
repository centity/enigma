#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "transformer.h"

class Reflector : public Transformer {
public:
    Reflector(char letters);
    char transform(char c);

};

#endif // REFLECTOR_H

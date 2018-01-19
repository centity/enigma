#include "reflector.h"

// Uses the base class constructor and transform fn
Reflector::Reflector(const char letters[])
    : Transformer(letters)
{
}

char Reflector::transform(char letter) {
    return this->Transformer::transform(letter, 0);
}

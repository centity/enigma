#include "reflector.h"

Reflector::Reflector(const char letters[])
    : Transformer(letters)
{
}

char Reflector::transform(char letter) {
    return this->Transformer::transform(letter, 0);
}

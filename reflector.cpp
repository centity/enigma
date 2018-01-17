#include "reflector.h"

Reflector::Reflector(char letters[])
    : Transformer(letters, letters)
{
}

char Reflector::transform(char letter) {
    return this->Transformer::transform(letter, 0);
}

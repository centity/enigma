#include "plugboard.h"

// Uses the base class constructor and transform
Plugboard::Plugboard(const char letters[])
    : Transformer(letters)
{
}

char Plugboard::transform(char letter) {
    return this->Transformer::transform(letter, 0);
}

char Plugboard::rTransform(char letter) {
    return this->Transformer::rTransform(letter, 0);
}

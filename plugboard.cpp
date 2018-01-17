#include "plugboard.h"

Reflector::Reflector(char letters[])
    : Transformer(letters, rLetters)
{
}

char Plugboard::transform(char letter) {
    return this->Transformer::transform(letter, 0);
}

char Plugboard::rTransform(char letter) {
    return this->Transformer::rTransform(letter, 0);
}

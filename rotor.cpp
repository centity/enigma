#include <iostream>
#include "rotor.h"

Rotor::Rotor(const char letters[], char notchLetter, int startPosition)
    : Transformer(letters)
    , notch(notchLetter - 'a')
    , offset(startPosition)
{
}

char Rotor::transform(char letter){
    return this->Transformer::transform(letter, offset);
}

char Rotor::rTransform(char letter){
    return this->Transformer::rTransform(letter, offset);
}

void Rotor::rotate(){
    offset++;
}

bool Rotor::isNotched(){
    return (offset % 26 == notch);
}


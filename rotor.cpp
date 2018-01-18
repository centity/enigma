#include <iostream>
#include "rotor.h"

Rotor::Rotor(const char letters[], int startPosition)
    : Transformer(letters)
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
    offset ++;
}


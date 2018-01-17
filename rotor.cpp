#include <iostream>
#include "rotor.h"

Rotor::Rotor(const char letters[], char start)
    : Transformer(letters)
    , offset(start - 'a')
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


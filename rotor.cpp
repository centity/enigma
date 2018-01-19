#include <iostream>
#include "rotor.h"

// Uses different constructor from base class to initalise the rotors
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

// Turs the rotor on once
void Rotor::step(){
    offset++;
}

// Checks for alignment with notch
bool Rotor::isNotched(){
    return (offset % 26 == notch);
}


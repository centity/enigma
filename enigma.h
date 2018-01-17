#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"

class Enigma {
public:
    char transform(char letter);
private:
    class Rotor lRotor, mRotor, rRotor;
    class Reflector reflector;
    class Plugboard plugboard;

};

#endif // ENIGMA_H

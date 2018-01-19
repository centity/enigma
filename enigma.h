#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"

class Enigma {
public:
    Enigma(const char plugMap[], int lRotNum, int lStartPosition, int mRotNum,
           int mStartPosition, int rRotNum, int rStartPosition, int refNum);
    char transform(char letter);

private:
    Plugboard plugboard;
    Rotor lRotor, mRotor, rRotor;
    Reflector reflector;

    int rotationCounter = 0;
};

#endif // ENIGMA_H

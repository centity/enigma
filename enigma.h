#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include <string>

class Enigma {
public:
    Enigma(const char plugMap[], int lRotNum, char lStartChar, int mRotNum,
           char mStartChar, int rRotNum, char rStartChar, int refNum);
    char transform(char letter);

private:
    Plugboard plugboard;
    Rotor lRotor, mRotor, rRotor;
    Reflector reflector;

    const char *rotMaps[5] = {
        "ekmflgdqvzntowyhxuspaibrcj",
        "ajdksiruxblhwtmcqgznpyfvoe",
        "bdfhjlcprtxvznyeiwgakmusqo",
        "esovpzjayquirhxlnftgkdcmwb",
        "vzbrgityupsdnhlxawmjqofeck"};

    const char *refMaps[2] = {
        "yruhqsldpxngokmiebfzcwvjat",
        "fvpjiaoyedrzxwgctkuqsbnmhl"};

    int rotationCounter = 0;
};

#endif // ENIGMA_H

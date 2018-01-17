#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"

class Enigma {
public:
    Enigma(const char plugMap[], int lRotNum, char lStartChar, int mRotNum,
           char mStartChar, int rRotNum, char rStartChar, int refNum);
    char transform(char letter);

private:
    Rotor lRotor, mRotor, rRotor;
    Reflector reflector;
    Plugboard plugboard;

    const char *rotMaps[5] = {
        "ekmflgdqvzntowyhxuspaibrcj",
        "ajdksiruxblhwtmcqgznpyfvoe",
        "bdfhjlcprtxvznyeiwgakmusqo",
        "esovpzjayquirhxlnftgkdcmwb",
        "vzbrgityupsdnhlxawmjqofeck"};

    const char *refMaps[2] = {
        "yruhqsldpxngokmiebfzcwvjat",
        "fvpjiaoyedrzxwgctkuqsbnmhl"};
};

#endif // ENIGMA_H

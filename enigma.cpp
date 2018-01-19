#include "enigma.h"
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include <string>

// Arrays to store the mapping of the rotors and reflectors
const static char *rotMaps[] = {
    "ekmflgdqvzntowyhxuspaibrcj",
    "ajdksiruxblhwtmcqgznpyfvoe",
    "bdfhjlcprtxvznyeiwgakmusqo",
    "esovpzjayquirhxlnftgkdcmwb",
    "vzbrgityupsdnhlxawmjqofeck"};

const static char rotNotch[] = "ymdrh";

const static char *refMaps[] = {
    "yruhqsldpxngokmiebfzcwvjat",
    "fvpjiaoyedrzxwgctkuqsbnmhl"};

// Enigma constructor passes the maps to the various transformer constructors
Enigma::Enigma(const char plugMap[], int lRotNum, int lStartPosition, int mRotNum,
       int mStartPosition, int rRotNum, int rStartPosition, int refNum)
    : plugboard(plugMap),
      lRotor(rotMaps[lRotNum], rotNotch[lRotNum], lStartPosition),
      mRotor(rotMaps[mRotNum], rotNotch[mRotNum], mStartPosition),
      rRotor(rotMaps[rRotNum], rotNotch[rRotNum], rStartPosition),
      reflector(refMaps[refNum])
{
}

// Self explanatory
char Enigma::transform(char letter) {
    if (rRotor.isNotched())
            mRotor.rotate();
    if (mRotor.isNotched())
            lRotor.rotate();

    letter = plugboard.transform(letter);
    letter = lRotor.transform(mRotor.transform(rRotor.transform(letter)));
    letter = reflector.transform(letter);
    letter = rRotor.rTransform(mRotor.rTransform(lRotor.rTransform(letter)));
    letter = plugboard.rTransform(letter);

    return letter;
}

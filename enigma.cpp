#include "enigma.h"
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include <string>

Enigma::Enigma(const char plugMap[], int lRotNum, char lStartChar, int mRotNum,
       char mStartChar, int rRotNum, char rStartChar, int refNum)
    : plugboard(plugMap),
      lRotor(rotMaps[lRotNum], lStartChar),
      mRotor(rotMaps[mRotNum], mStartChar),
      rRotor(rotMaps[rRotNum], rStartChar),
      reflector(refMaps[refNum])
{
}

char Enigma::transform(std::string toTransform) {
    char letter;
    int i = 0;
    while (i < toTransform.length()) {
        letter = toTransform[i];
        letter = plugboard.transform(letter);
        letter = lRotor.transform(mRotor.transform(rRotor.transform(letter)));
        letter = reflector.transform(letter);
        letter = rRotor.rTransform(mRotor.rTransform(lRotor.rTransform(letter)));
        letter = plugboard.rTransform(letter);

        i++;
        rRotor.rotate(); // Every letter
        if (i % 26 == 0) {mRotor.rotate();} // Every 26 rotates of rRotor
        if (i % 676 == 0) {lRotor.rotate();} // Every 26 rotates of mRotor
    }

    return letter;
}

#include "enigma.h"
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"

Enigma::Enigma(const char plugMap[], int lRotNum, char lStartChar, int mRotNum,
       char mStartChar, int rRotNum, char rStartChar, int refNum)
    : plugboard(plugMap),
      lRotor(rotMaps[lRotNum], lStartChar),
      mRotor(rotMaps[mRotNum], mStartChar),
      rRotor(rotMaps[rRotNum], rStartChar),
      reflector(refMaps[refNum])
{
    rotationCounter = 0;
}

char Enigma::transform(char toTransform){
    char letter = toTransform;
    letter = plugboard.transform(letter);
    letter = lRotor.transform(mRotor.transform(rRotor.transform(letter)));
    letter = reflector.transform(letter);
    letter = rRotor.rTransform(mRotor.rTransform(lRotor.rTransform(letter)));
    letter = plugboard.rTransform(letter);

    rotationCounter ++;
    rRotor.rotate();
    if (rotationCounter % 26 == 0) {mRotor.rotate();}
    if (rotationCounter % 676 == 0) {lRotor.rotate();}

    return letter;
}

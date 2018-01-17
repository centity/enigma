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

}

char Enigma::transform(char letter){
    letter = plugboard.transform(letter);
    letter = lRotor.transform(mRotor.transform(rRotor.transform(letter)));
    letter = reflector.transform(letter);
    letter = rRotor.rTransform(mRotor.rTransform(lRotor.rTransform(letter)));
    letter = plugboard.rTransform(letter);


    return letter;
}

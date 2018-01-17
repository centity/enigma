#include "enigma.h"
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"

Enigma(const char plugMap[], int lRotNum, int lRotOff, int mRotNum,
       int mRotOff, int rRotNum, int rRotOff, int refNum)
    : plugboard(plugMap),
      lRotor(rotMaps[lRotNum], lRotOff),
      mRotor(rotMaps[mRotNum], mRotOff),
      rRotor(rotMaps[rRotNum], rRotOff),
      reflector(refMaps[refNum])
{

}

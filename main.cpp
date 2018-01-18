#include <iostream>
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include "enigma.h"

int main()
{
    // Placeholders
    char plugMap[] = "abcdefghijklmnopqrstuvwxyz";
    int lRotNum = 0, mRotNum = 0, rRotNum = 0;
    char lStartChar = 'a', mStartChar = 'a', rStartChar = 'a';
    int refNum = 0;

    Enigma enigma(plugMap, lRotNum, lStartChar, mRotNum,
                  mStartChar, rRotNum, rStartChar, refNum);

    enigma.transform('a');

    /*
    char test[] = "test";
    for (int i = 0; i < 4; i++){
        test[i] = enigma.transform(test[i]);
        std::cout << test[i];
    }
    */
}

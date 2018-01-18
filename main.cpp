#include <iostream>
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include "enigma.h"

int main(int argc, char **argv)
{
    // Placeholders
    char plugMap[] = "abcdefghijklmnopqrstuvwxyz";
    int lRotNum = 2, mRotNum = 3, rRotNum = 4;
    char lStartChar = 'f', mStartChar = 'a', rStartChar = 'z';
    int refNum = 1;

    Enigma enigma(plugMap, lRotNum, lStartChar, mRotNum,
                  mStartChar, rRotNum, rStartChar, refNum);

    //char *p = argv[1];
    char *p = "vrsctebghtuopiefpgrotughbcsdasxpdqhwwdzvze";
    while (*p) {
        std::cout << enigma.transform(*p);
    ++p;
    }

    /*
    char test[] = "test";
    for (int i = 0; i < 4; i++){
        test[i] = enigma.transform(test[i]);
        std::cout << test[i];
    }
    */
}

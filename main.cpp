#include <iostream>
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include "enigma.h"

using namespace std;

int main()
{
    char plugMap[] = "abcdefghijklmnopqrstuvwxyz";
    int lRotNum = 2, mRotNum = 1, rRotNum = 0;
    int lStartPosition = 0, mStartPosition = 0, rStartPosition = 0;
    int refNum = 0;

    cout << "Welcome to Enigma" << endl;

    Enigma enigma(plugMap, lRotNum, lStartPosition, mRotNum,
                  mStartPosition, rRotNum, rStartPosition, refNum);

    const char *p = "vdhwq";
    while (*p) {
        std::cout << enigma.transform(*p);
    ++p;
    }
}

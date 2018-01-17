#include <iostream>
#include "rotor.h"

int main()
{
    int lRot, mRot, rRot;
    char lStart, mStart, rStart;
    int lOffset, mOffset, rOffset;
    char chr;

    /*
    // Letter mapping of each rotor
    char rMaps[5][27] = {
        "ekmflgdqvzntowyhxuspaibrcj",
        "ajdksiruxblhwtmcqgznpyfvoe",
        "bdfhjlcprtxvznyeiwgakmusqo",
        "esovpzjayquirhxlnftgkdcmwb",
        "vzbrgityupsdnhlxawmjqofeck"};
    */

    char rMaps[5][27] = {
        "abcdefghijklmnopqrstuvwxyz",
        "abcdefghijklmnopqrstuvwxyz",
        "abcdefghijklmnopqrstuvwxyz",
        "abcdefghijklmnopqrstuvwxyz",
        "abcdefghijklmnopqrstuvwxyz"};


    // To become user defined
    lRot = 2, mRot = 1, rRot = 0;
    lStart = 'a', mStart = 'a', rStart = 'a';
    char input[] = "test";

    // Set the offset based on the start position of each rotor
    lOffset = lStart - 97, mOffset = mStart - 97, rOffset = rStart - 97;

    Rotor lRotor(rMaps[lRot], &lOffset);
    Rotor mRotor(rMaps[mRot], &mOffset);
    Rotor rRotor(rMaps[rRot], &rOffset);

    int i = 0;
    while (i < 4){
        chr = input[i];
        chr = lRotor.transform(mRotor.transform(rRotor.transform(chr)));
        std::cout << chr;

        i++;

        // Right rotor turns every time, middle and right rotor turn
        // every 26 turns of the rotor to its right
        rOffset ++;
        if (i % 26 == 0) {mOffset ++;}
        if (i % 676 == 0) {rOffset ++;}
    }
}

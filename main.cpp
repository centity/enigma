#include <iostream>
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include "enigma.h"

int main()
{
    //Enigma enigma("abcdefghijklmnopqrstuvw", )
    int lRot, mRot, rRot;
    int ref;
    char lStart, mStart, rStart;
    int lOffset, mOffset, rOffset;
    char chr;

    char rotMaps[5][27] = {
        "ekmflgdqvzntowyhxuspaibrcj",
        "ajdksiruxblhwtmcqgznpyfvoe",
        "bdfhjlcprtxvznyeiwgakmusqo",
        "esovpzjayquirhxlnftgkdcmwb",
        "vzbrgityupsdnhlxawmjqofeck"};

    char refMaps[2][27] = {
        "yruhqsldpxngokmiebfzcwvjat",
        "fvpjiaoyedrzxwgctkuqsbnmhl"};

    char plugMap[27] = {
        "abcdefghijklmnopqrstuvwxyz"};



    // To become user defined
    lRot = 2, mRot = 1, rRot = 0;
    ref = 0;
    lStart = 'a', mStart = 'a', rStart = 'a';
    char input[] = "test";

    // Set the offset based on the start position of each rotor
    lOffset = lStart - 'a', mOffset = mStart - 'a', rOffset = rStart - 'a';

    Rotor lRotor(rotMaps[lRot], lOffset);
    Rotor mRotor(rotMaps[mRot], mOffset);
    Rotor rRotor(rotMaps[rRot], rOffset);
    Reflector reflector(refMaps[ref]);
    Plugboard plugboard(plugMap);

    int i = 0;
    while (i < 4){
        chr = input[i];
        chr = plugboard.transform(chr);
        chr = lRotor.transform(mRotor.transform(rRotor.transform(chr)));
        chr = reflector.transform(chr);
        std::cout << chr;

        i++;


        rRotor.rotate();
        if (i % 26 == 0) {mRotor.rotate();} // Every 26 turns of rRotor
        if (i % 676 == 0) {lRotor.rotate();} // Every 26 turns of mROtor
    }
}

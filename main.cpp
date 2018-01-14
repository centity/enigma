#include <iostream>
#include "rotor.h"

int main()
{
    Rotor rI("ekmflgdqvzntowyhxuspaibrcj");
    Rotor rII("ajdksiruxblhwtmcqgznpyfvoe");
    Rotor rIII("bdfhjlcprtxvznyeiwgakmusqo");
    Rotor rIV("esovpzjayquirhxlnftgkdcmwb");
    Rotor rV("vzbrgityupsdnhlxawmjqofeck");


    rIII.transform(rII.transform(rI.transform('a')));


}

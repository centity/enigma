#include <iostream>
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include "enigma.h"

using namespace std;


int main()
{
    int mode;
    char plugMap[] = "abcdefghijklmnopqrstuvwxyz";
    int lRotNum = 2, mRotNum = 1, rRotNum = 0;
    int lStartPosition = 0, mStartPosition = 0, rStartPosition = 0;
    int refNum = 0;

    cout << "\nWelcome to Enigma.\n\n";
    while (true){
        cout << " 1) Transform message\n";
        cout << " 2) View settings\n";
        cout << " 3) Alter settings\n";
        cout << " 0) Quit\n";
        mode = getInt(0, 3);

        if (mode == 1){
            Enigma enigma(plugMap, lRotNum, lStartPosition, mRotNum,
                          mStartPosition, rRotNum, rStartPosition, refNum);
            cout << "Enter a lowercase message without whitespace: \n";
            // Take message and output transformation
            Enigma ~enigma();
        }

        else if (mode == 2){
            cout << "Left rotor: " << lRotNum + 1 << " start position: " << lStartPosition + 1 << " / ";
            cout << "Middle rotor: " << mRotNum + 1 << " start position: " << mStartPosition + 1 << "  / ";
            cout << "Right rotor: " << rRotNum + 1 << " start position: " << rStartPosition + 1 << "/n";
            cout << "Reflector: " << refNum + 1 << "\n";
            cout << "Plugboard map: ";
            for (int i = 0; i < 26 < i++){
                cout << plugMap[i];
            }
            cout << endl;
        }

        else if (mode == 3){
            int setting;
            while (true){
                cout << " 1) Rotors\n";
                cout << " 2) Rotor offsets\n";
                cout << " 3) Reflector\n";
                cout << " 4) Plugboard pairs\n";
                cout << " 0) Back\n";
                setting = getInt(0, 4);

                if (setting == 1){
                    "Select rotors from 1 - 5.\n";

                    "Left: \n";
                    lRotNum = getInt(1, 5) - 1;
                    "Middle: \n";
                    mRotNum = getInt(1, 5) - 1;
                    "Right: \n";
                    rRotNum = getInt(1, 5) - 1;
                }

                if (setting == 2){
                    cout << "Set the rotor offsets from 0 - 26. \n";

                    "Left: \n";
                    lStartPosition = getInt(0, 26) - 1;
                    "Middle: \n";
                    mStartPosition = getInt(0, 26) - 1;
                    "Right: \n";
                    rStartPosition = getInt(0, 26) - 1;
                }

                if (setting == 3){
                    cout << "Choose reflector 1 or 2: ";
                    refNum = getInt(1,2) - 1;
                }

                if (setting == 4){
                    char a, b;
                    int toSwap;
                    cout << "How many pairs of characters would you like to swap?\n";
                    cout << "(You may swap up to 6)\n";
                    toSwap = getInt(0,6);

                    if (toSwap != 0){
                        for (int i = 0; i < toSwap; i++){
                            cout << "Pair " << i + 1 << ". Swap: ";
                            a = getChar();
                            cout << " and: ";
                            b = getChar();
                            plugMap[a - 'a'] = b;
                            plugMap[b - 'a'] = a;
                        }
                    }
                }

                if (setting == 0){
                    break;
                }

            }

        }

        else if (mode == 0){
            break;
        }

    }

    return 0;
}


int getInt(int lower, int upper){
    int input;
    while (!(cin >> input) || input < lower || input > upper){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '/n');
        cout << "Enter an integer from " << lower << " - " << upper << ":\n";
    }
    return input;
}

// Need to implement protection against non char input
int getChar(){
    char input;
    cin << input;
    return input;
}

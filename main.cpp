#include <iostream>
#include <limits>
#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"
#include "enigma.h"

using namespace std;

int getChar();
int getInt(int lower, int upper);
bool isAllowed(char a);

int main()
{

    // Default enigma settings
    char plugMap[] = "abcdefghijklmnopqrstuvwxyz";
    int lRotNum = 2, mRotNum = 1, rRotNum = 0;
    int lStartPosition = 0, mStartPosition = 0, rStartPosition = 0;
    int refNum = 0;

    int mode;

    // CLI with user menus
    cout << endl << "Welcome to Enigma."<< endl;
    while (true) {
        cout << endl << " 1) Transform message" << endl;
        cout << " 2) View settings" << endl;
        cout << " 3) Alter settings" << endl;
        cout << " 0) Quit" << endl;
        mode = getInt(0, 3);

        // Transform message
        if (mode == 1) {
            string message;
            int messageLength;
            Enigma enigma(plugMap, lRotNum, lStartPosition, mRotNum,
                          mStartPosition, rRotNum, rStartPosition, refNum);

            cout << "Enter a lowercase message without whitespace: " << endl;
            cin >> message;
            messageLength = message.length();

            for (int i = 0; i < messageLength; i++) {
                char letter = message[i];
                if (isAllowed(letter)) {
                    letter = enigma.transform(letter);
                    cout << letter;
                }
            }
            cout << endl;
        }

        // View settings
        else if (mode == 2) {
            cout << endl << "Left rotor: " << lRotNum + 1 << " / Start position: " << lStartPosition + 1 << endl;
            cout << "Middle rotor: " << mRotNum + 1 << " / Start position: " << mStartPosition + 1 << endl;
            cout << "Right rotor: " << rRotNum + 1 << " / Start position: " << rStartPosition + 1 << endl;
            cout << "Reflector: " << refNum + 1 << endl;
            cout << "Plugboard map: ";
            for (int i = 0; i < 26; i++) {
                cout << plugMap[i];
            }
            cout << endl;
        }

        // Menu for changing enigma settings
        else if (mode == 3) {
            int setting;
            while (true) {
                cout << endl << " 1) Rotors" << endl;
                cout << " 2) Rotor offsets" << endl;
                cout << " 3) Reflector" << endl;
                cout << " 4) Plugboard pairs" << endl;
                cout << " 0) Back" << endl;
                setting = getInt(0, 4);

                // Chooses rotor
                if (setting == 1) {
                    cout << "Select rotors from 1 - 5." << endl;

                    cout << "Left: ";
                    lRotNum = getInt(1, 5) - 1;
                    cout << "Middle: ";
                    mRotNum = getInt(1, 5) - 1;
                    cout << "Right: ";
                    rRotNum = getInt(1, 5) - 1;
                }

                // Sets initial position of each rotor
                if (setting == 2) {
                    cout << "Set the rotor start positions from 1 - 26. " << endl;

                    cout << "Left: ";
                    lStartPosition = getInt(1, 26) - 1;
                    cout << "Middle: ";
                    mStartPosition = getInt(1, 26) - 1;
                    cout << "Right: ";
                    rStartPosition = getInt(1, 26) - 1;
                }

                // Choosing reflector
                if (setting == 3) {
                    cout << "Choose reflector 1 or 2: ";
                    refNum = getInt(1,2) - 1;
                }

                // Setting plugboard
                if (setting == 4) {
                    int toSwap;
                    cout << "How many pairs of characters would you like to swap?" << endl;
                    cout << "(You may swap up to 6)" << endl;
                    toSwap = getInt(0,6);

                    // Creates letter pairs which map to one another in plugboard
                    for (int i = 0; i < toSwap; i++) {
                        char a, b;
                        cout << "Pair " << i + 1 << ". Swap: ";
                        a = getChar();
                        cout << " and: ";
                        b = getChar();
                        plugMap[a - 'a'] = b;
                        plugMap[b - 'a'] = a;
                    }
                }

                // Quit
                if (setting == 0)
                    break;
            }

        }

        else if (mode == 0)
            break;
    }

    return 0;
}

// Takes a char from the user
int getChar() {
    char input;
    while (true) {
        cin >> input;
        if (isAllowed(input))
            break;
    }
    return input;
}


// Takes user input and checks if it is a valid integer
int getInt(int lower, int upper) {
    int input;
    while (!(cin >> input) || input < lower || input > upper) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // cout << "Enter an integer from " << lower << " - " << upper << ":" << endl;
    }
    return input;
}


// Checks if user input is lowercase a-z
bool isAllowed(char a) {
    return (a >= 'a' && a <= 'z');
}

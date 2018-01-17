#ifndef PLUGBOARD_H
#define PLUGBOARD_H


class Plugboard
{
public:
    Plugboard(const char letters[], const char rLetters[]);
    char transform(char letter);
    char rTransform(char letter);
};

#endif // PLUGBOARD_H

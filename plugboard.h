#ifndef PLUGBOARD_H
#define PLUGBOARD_H


class Plugboard
{
public:
    Plugboard(char letters[]);
    char transform(char letter);

private:
    char map[26];
};

#endif // PLUGBOARD_H

#ifndef TRANSFORMER_H
#define TRANSFORMER_H


class Transformer {
public:
    Transformer(const char letters[], const char rLetters[]);
    char transform(char letter, int offset);
    char rTransform(char letter, int offset);

private:
    char map[26];
    char rMap[26];
};

#endif // TRANSFORMER_H

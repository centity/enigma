#ifndef TRANSFORMER_H
#define TRANSFORMER_H


class Transformer {
public:
    Transformer();
    char transform(char c, int offset);

private:
    char map[27];
};

#endif // TRANSFORMER_H

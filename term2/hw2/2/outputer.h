#pragma once

class Outputer
{
public:
    Outputer(int **currentArray, int currentSize);
    void snake();
protected:
    int size;
    int **array;
};

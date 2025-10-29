#ifndef ARRAY_PROCESSOR_H
#define ARRAY_PROCESSOR_H

#include <iostream>
#include <cstring>
#include <cctype>


class ArrayProcessor {
public:

    static bool isLetterA(char c);

    static bool isLetter(char c);
    

    static void processString(char str[]);
    

    static void run();
};

#endif

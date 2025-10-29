#ifndef CSTRING_PROCESSOR_H
#define CSTRING_PROCESSOR_H

#include <iostream>
#include <cstring>
#include <cctype>


class CStringProcessor {
public:

    static bool isLetterA(char c);
    

    static bool isLetter(char c);
    

    static void processCString(char* str);

    static void run();
};

#endif

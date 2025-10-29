#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>


class FileProcessor {
public:

    static bool isLetterA(char c);
    

    static bool isLetter(char c);

    static void processString(char str[]);
    

    static void run();
};

#endif

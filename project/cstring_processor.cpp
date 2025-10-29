#include "cstring_processor.h"

bool CStringProcessor::isLetterA(char c) {
    return (c == 'А' || c == 'а' || c == 'A' || c == 'a');
}

bool CStringProcessor::isLetter(char c) {
    return ((c >= 'А' && c <= 'я') || (c >= 'A' && c <= 'z'));
}

void CStringProcessor::processCString(char* str) {
    char* readPtr = str;
    char* writePtr = str;
    bool inWord = false;
    char* wordStart = nullptr;
    int wordLength = 0;
    
    while (*readPtr != '\0') {
        if (isLetter(*readPtr)) {
            if (!inWord) {
                // Начало нового слова
                inWord = true;
                wordStart = readPtr;
                wordLength = 1;
            } else {
                // Продолжение слова
                wordLength++;
            }
        } else {
            if (inWord) {
                // Конец слова - проверяем условие
                if (isLetterA(*wordStart) && wordLength > 3) {
                    // Заменяем слово на его длину
                    char numStr[10];
                    sprintf(numStr, "%d", wordLength);
                    char* numPtr = numStr;
                    while (*numPtr != '\0') {
                        *writePtr++ = *numPtr++;
                    }
                } else {
                    // Копируем слово как есть
                    char* temp = wordStart;
                    for (int i = 0; i < wordLength; i++) {
                        *writePtr++ = *temp++;
                    }
                }
                inWord = false;
                wordLength = 0;
            }
            *writePtr++ = *readPtr;
        }
        readPtr++;
    }
    
    // Обработка последнего слова
    if (inWord) {
        if (isLetterA(*wordStart) && wordLength > 3) {
            char numStr[10];
            sprintf(numStr, "%d", wordLength);
            char* numPtr = numStr;
            while (*numPtr != '\0') {
                *writePtr++ = *numPtr++;
            }
        } else {
            char* temp = wordStart;
            for (int i = 0; i < wordLength; i++) {
                *writePtr++ = *temp++;
            }
        }
    }
    
    *writePtr = '\0';
}

void CStringProcessor::run() {
    const int MAX_LENGTH = 1000;
    char* str = new char[MAX_LENGTH];
    
    std::cout << "=== Обработка как C-строки ===" << std::endl;
    std::cout << "Введите строку: ";
    std::cin.getline(str, MAX_LENGTH);
    
    std::cout << "Исходная строка: " << str << std::endl;
    
    processCString(str);
    
    std::cout << "Результат: " << str << std::endl;
    
    delete[] str;
}

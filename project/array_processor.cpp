#include "array_processor.h"

bool ArrayProcessor::isLetterA(char c) {
    return (c == 'А' || c == 'а' || c == 'A' || c == 'a');
}

bool ArrayProcessor::isLetter(char c) {
    return ((c >= 'А' && c <= 'я') || (c >= 'A' && c <= 'z'));
}

void ArrayProcessor::processString(char str[]) {
    int i = 0, j = 0;
    bool inWord = false;
    int wordStart = 0;
    int wordLength = 0;
    
    while (str[i] != '\0') {
        if (isLetter(str[i])) {
            if (!inWord) {
                // Начало нового слова
                inWord = true;
                wordStart = i;
                wordLength = 1;
            } else {
                // Продолжение слова
                wordLength++;
            }
        } else {
            if (inWord) {
                // Конец слова - проверяем условие
                if (isLetterA(str[wordStart]) && wordLength > 3) {
                    // Заменяем слово на его длину
                    char numStr[10];
                    sprintf(numStr, "%d", wordLength);
                    for (int k = 0; numStr[k] != '\0'; k++) {
                        str[j++] = numStr[k];
                    }
                } else {
                    // Копируем слово как есть
                    for (int k = wordStart; k < i; k++) {
                        str[j++] = str[k];
                    }
                }
                inWord = false;
            }
            // Копируем разделитель
            str[j++] = str[i];
        }
        i++;
    }
    
    // Обработка последнего слова
    if (inWord) {
        if (isLetterA(str[wordStart]) && wordLength > 3) {
            char numStr[10];
            sprintf(numStr, "%d", wordLength);
            for (int k = 0; numStr[k] != '\0'; k++) {
                str[j++] = numStr[k];
            }
        } else {
            for (int k = wordStart; k < i; k++) {
                str[j++] = str[k];
            }
        }
    }
    
    str[j] = '\0';
}

void ArrayProcessor::run() {
    const int MAX_LENGTH = 1000;
    char str[MAX_LENGTH];
    
    std::cout << "=== Обработка как массива символов ===" << std::endl;
    std::cout << "Введите строку: ";
    std::cin.getline(str, MAX_LENGTH);
    
    std::cout << "Исходная строка: " << str << std::endl;
    
    processString(str);
    
    std::cout << "Результат: " << str << std::endl;
}

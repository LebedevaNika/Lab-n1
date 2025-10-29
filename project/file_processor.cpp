#include "file_processor.h"

bool FileProcessor::isLetterA(char c) {
    return (c == 'А' || c == 'а' || c == 'A' || c == 'a');
}

bool FileProcessor::isLetter(char c) {
    return ((c >= 'А' && c <= 'я') || (c >= 'A' && c <= 'z'));
}

void FileProcessor::processString(char str[]) {
    int i = 0, j = 0;
    bool inWord = false;
    int wordStart = 0;
    int wordLength = 0;
    
    while (str[i] != '\0') {
        if (isLetter(str[i])) {
            if (!inWord) {
                inWord = true;
                wordStart = i;
                wordLength = 1;
            } else {
                wordLength++;
            }
        } else {
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
                inWord = false;
            }
            str[j++] = str[i];
        }
        i++;
    }
    
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

void FileProcessor::run() {
    const int MAX_LENGTH = 1000;
    char str[MAX_LENGTH];
    
    std::cout << "=== Обработка файлов ===" << std::endl;
    
    // Открываем файл для чтения
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cout << "Ошибка: не могу открыть input.txt" << std::endl;
        std::cout << "Создайте файл input.txt с тестовой строкой" << std::endl;
        return;
    }
    
    // Читаем строку из файла
    inputFile.getline(str, MAX_LENGTH);
    inputFile.close();
    
    // Удаляем символ новой строки если есть
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    
    std::cout << "Прочитана строка: " << str << std::endl;
    
    // Обрабатываем строку
    processString(str);
    
    std::cout << "Результат обработки: " << str << std::endl;
    
    // Записываем в выходной файл
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cout << "Ошибка создания output.txt" << std::endl;
        return;
    }
    
    outputFile << str;
    outputFile.close();
    
    std::cout << "Результат записан в output.txt" << std::endl;
}

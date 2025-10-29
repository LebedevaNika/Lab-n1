#include <iostream>
#include "array_processor.h"
#include "cstring_processor.h"
#include "file_processor.h"

/**
 * Главная программа демонстрирует три способа обработки строк:
 * 1. Как массива символов
 * 2. Как C-строки  
 * 3. Через файлы
 */
int main() {
    int choice;
    
    std::cout << "=== ОБРАБОТКА СТРОК РАЗЛИЧНЫМИ СПОСОБАМИ ===" << std::endl;
    std::cout << "Задание: Удалить слова, начинающиеся на 'а'" << std::endl;
    std::cout << "         (длиной > 3), заменив их на длину" << std::endl;
    std::cout << std::endl;
    
    do {
        std::cout << "Выберите способ обработки:" << std::endl;
        std::cout << "1. Как массив символов" << std::endl;
        std::cout << "2. Как C-строка" << std::endl;
        std::cout << "3. Через файлы (input.txt -> output.txt)" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(); // Очищаем буфер после ввода числа
        
        switch (choice) {
            case 1:
                ArrayProcessor::run();
                break;
            case 2:
                CStringProcessor::run();
                break;
            case 3:
                FileProcessor::run();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
        }
        std::cout << std::endl;
        
    } while (choice != 0);
    
    return 0;
}

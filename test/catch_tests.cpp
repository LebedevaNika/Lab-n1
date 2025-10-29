#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "char_array_operations.h"
#include "string_manipulation.h"
#include "file_processing.h"
#include <fstream>
#include <cstring>

TEST_CASE("Базовое распознавание букв 'а'", "[basic]") {
    SECTION("Русские буквы") {
        REQUIRE(TextModifier::startsWithA('а') == true);
        REQUIRE(TextModifier::startsWithA('А') == true);
        REQUIRE(TextModifier::startsWithA('б') == false);
    }
    
    SECTION("Английские буквы") {
        REQUIRE(TextModifier::startsWithA('a') == true);
        REQUIRE(TextModifier::startsWithA('A') == true);
        REQUIRE(TextModifier::startsWithA('b') == false);
    }
}

TEST_CASE("Обработка массива символов", "[array]") {
    SECTION("Замена длинных слов на 'а'") {
        char test1[] = "Анна арбуз апельсин";
        TextModifier::transformText(test1);
        REQUIRE(std::string(test1) == "4 5 8");
        
        char test2[] = "apple atmosphere";
        TextModifier::transformText(test2);
        REQUIRE(std::string(test2) == "5 10");
    }
    
    SECTION("Короткие слова на 'а' остаются") {
        char test[] = "аист аня аз";
        TextModifier::transformText(test);
        REQUIRE(std::string(test) == "аист аня аз");
    }
    
    SECTION("Смешанный текст") {
        char test[] = "Анна и арбуз тут яблоко";
        TextModifier::transformText(test);
        REQUIRE(std::string(test) == "4 и 5 тут яблоко");
    }
}

TEST_CASE("Обработка C-строк", "[cstring]") {
    SECTION("Динамическая память") {
        char* test = new char[100];
        strcpy(test, "апельсин арбуз автомобиль");
        CStringHandler::modifyString(test);
        REQUIRE(std::string(test) == "8 5 9");
        delete[] test;
    }
    
    SECTION("Сохранение других слов") {
        char* test = new char[100];
        strcpy(test, "яблоко апельсин груша");
        CStringHandler::modifyString(test);
        REQUIRE(std::string(test) == "яблоко 8 груша");
        delete[] test;
    }
}

TEST_CASE("Граничные случаи", "[edge]") {
    SECTION("Пустая строка") {
        char test[] = "";
        TextModifier::transformText(test);
        REQUIRE(std::string(test) == "");
    }
    
    SECTION("Строка без слов на 'а'") {
        char test[] = "привет мир hello";
        TextModifier::transformText(test);
        REQUIRE(std::string(test) == "привет мир hello");
    }
    
    SECTION("Только разделители") {
        char test[] = "   , . ! ";
        TextModifier::transformText(test);
        REQUIRE(std::string(test) == "   , . ! ");
    }
}

TEST_CASE("Работа с файлами", "[file]") {
    SECTION("Чтение и запись файлов") {
        // Создаем тестовый файл
        std::ofstream out("test_input.txt");
        out << "Анна арбуз апельсин";
        out.close();
        
        // Обрабатываем
        std::ifstream in("test_input.txt");
        char buffer[100];
        in.getline(buffer, 100);
        in.close();
        
        DocumentManager::editContent(buffer);
        REQUIRE(std::string(buffer) == "4 5 8");
        
        // Записываем результат
        std::ofstream result("test_output.txt");
        result << buffer;
        result.close();
        
        // Проверяем что файл создан
        std::ifstream check("test_output.txt");
        REQUIRE(check.is_open() == true);
        check.close();
    }
}

TEST_CASE("Сложные сценарии", "[complex]") {
    SECTION("Разные регистры") {
        char test[] = "Анна арбуз АПЕЛЬСИН";
        TextModifier::transformText(test);
        REQUIRE(std::string(test) == "4 5 8");
    }
    
    SECTION("Множественные пробелы") {
        char test[] = "Анна   арбуз";
        TextModifier::transformText(test);
        REQUIRE(std::string(test) == "4   5");
    }
    
    SECTION("Слова с символами") {
        char test[] = "анна! арбуз? апельсин.";
        TextModifier::transformText(test);
        REQUIRE(std::string(test) == "анна! арбуз? 8.");
    }
}

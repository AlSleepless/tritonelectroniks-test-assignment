#ifndef TRITONEELECTRONNIKS_TEST_ASSIGNMENT
#define TRITONEELECTRONNIKS_TEST_ASSIGNMENT

#include <cstdint>
#include <map>
#include <string>
#include <vector>

/*  Task 1  */
/*
Задача № 1. Дан std::vector<std::string> words. Напишите быструю функцию,
которая не изменяя исходный массив вернет первую строку, встречающуюся в векторе
ровно один раз. Если таких нет, верните "" (написание функции main, заполнение
массива можно опустить, оставив только подключаемые файлы и функцию).
*/

std::string getFirstUnique(const std::vector<std::string> &words);

#endif
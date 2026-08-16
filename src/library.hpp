#ifndef TRITONEELECTRONNIKS_TEST_ASSIGNMENT
#define TRITONEELECTRONNIKS_TEST_ASSIGNMENT

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

/*  Task 1  */
/*
Задача № 1. Дан std::vector<std::string> words. Напишите быструю функцию,
которая не изменяя исходный массив вернет первую строку, встречающуюся в векторе
ровно один раз. Если таких нет, верните "" (написание функции main, заполнение
массива можно опустить, оставив только подключаемые файлы и функцию).
*/

std::string getFirstUnique(const std::vector<std::string> &words);

/*  Task 2  */
/*
Задача № 2.  Дан следующий код:
Вопросы:
1. Какие проблемы имеются в коде?
2. Если да, тогда объясните механизм возникновения, предложите исправление либо
опишите словами, чтобы вы исправили.
----
Ответы:
1 возврат ссылки на локальнную переменную в createWorker())
2 нет включения необходимой библиотеки "memory" для shared_ptr
3 циклический shared_ptr в лямбда функции
Решение реализовано и проверено модульнымии тестами
*/

struct Worker {
  std::string name;
  std::function<void()> onDone;

  explicit Worker(std::string n) : name{n} {}

  std::string getNameInLowerCase();
};

std::shared_ptr<Worker> createWorker(std::string name);

// int main() { // переимендовал для простой сборки вместе с первой задачей
int workerMain();

#endif
/*  Task 2  */
/*
Задача № 2.  Дан следующий код:
Вопросы:
1. Какие проблемы имеются в коде?
2. Если да, тогда объясните механизм возникновения, предложите исправление либо
опишите словами, чтобы вы исправили.
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

struct Worker {
  std::string name;
  std::function<void()> onDone;

  explicit Worker(std::string n) : name{n} {}

  std::string &getNameInLowerCase() {
    std::string lc{name};
    std::transform(lc.begin(), lc.end(), lc.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lc; //! Проблема 1 - возврат ссылки на локальнную переменную
  }
};

//! Проблема 2 - нет включения необходимой библиотеки "memory" для shared_ptr
std::shared_ptr<Worker> createWorker(std::string name) {
  auto worker{std::make_shared<Worker>(name)};
  worker->onDone = [worker]() { //! Проблема 3 - циклический shared_ptr
    std::cout << "Task " << worker->name << " completed.\n";
  };

  return worker;
}

int main() {
  auto worker{createWorker("IDLE")};

  std::cout << "Worker name: " << worker->getNameInLowerCase() << std::endl;
  worker->onDone();

  return 0;
}

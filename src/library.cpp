#include "library.hpp"

/*  Task 1  */

std::string getFirstUnique(const std::vector<std::string> &words) {
  std::unordered_map<std::string, std::size_t> wordCounter{};
  for (auto &word : words) {
    ++wordCounter[word];
  }
  for (auto &word : words) {
    if (wordCounter.at(word) == 1) {
      return word;
    }
  }
  return "";
}

/*  Task 2  */

std::string Worker::getNameInLowerCase() {
  std::string lc{name};
  std::transform(lc.begin(), lc.end(), lc.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return lc;
}

std::shared_ptr<Worker> createWorker(std::string name) {
  auto worker{std::make_shared<Worker>(name)};
  std::weak_ptr<Worker> weakWorker = worker;
  worker->onDone = [weakWorker]() {
    if (auto sharedWorker = weakWorker.lock()) {
      std::cout << "Task " << sharedWorker->name << " completed.\n";
    }
  };

  return worker;
}

int workerMain() {
  auto worker{createWorker("IDLE")};

  std::cout << "Worker name: " << worker->getNameInLowerCase() << std::endl;
  worker->onDone();

  return 0;
}
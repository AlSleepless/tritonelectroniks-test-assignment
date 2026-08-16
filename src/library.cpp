#include "library.hpp"

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
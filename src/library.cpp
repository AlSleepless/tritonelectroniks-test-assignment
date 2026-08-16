#include "library.hpp"

std::string getFirstUnique(const std::vector<std::string> &words) {
  std::map<std::string, std::size_t> wordCounter{};
  for (auto &word : words) {
    ++wordCounter[word];
  }
  for (auto &[word, count] : wordCounter) {
    if (count == 1) {
      return word;
    }
  }
  return "";
}
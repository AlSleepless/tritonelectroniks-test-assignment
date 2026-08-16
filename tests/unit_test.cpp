#include "library.hpp"

#include <gtest/gtest.h>

TEST(Task1, Positive1) {
  std::vector<std::string> testCase{"word1", "word2", "word3"};
  std::string res = getFirstUnique(testCase);
  ASSERT_EQ(res, "word1");
}

TEST(Task1, Positive2) {
  std::vector<std::string> testCase{"word1", "word2", "word3", "word1"};
  std::string res = getFirstUnique(testCase);
  ASSERT_EQ(res, "word2");
}
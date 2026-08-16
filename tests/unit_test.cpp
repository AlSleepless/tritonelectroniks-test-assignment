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

TEST(Task1, Negative1) {
  std::vector<std::string> testCase{"word1", "word1"};
  std::string res = getFirstUnique(testCase);
  ASSERT_EQ(res, "");
}

TEST(Task2, Positive1) {
  Worker worker("Jhon Smit");
  ASSERT_EQ(worker.name, "Jhon Smit");
}

TEST(Task2, Positive2) {
  auto worker{createWorker("Jhon Smit")};
  ASSERT_NE(worker, nullptr);
}

TEST(Task2, Positive3) {
  auto worker{createWorker("Jhon Smit")};
  std::string res = worker->getNameInLowerCase();
  ASSERT_EQ(res, "jhon smit");
}

TEST(Task2, Positive4) {
  auto worker{createWorker("Jhon Smit")};
  testing::internal::CaptureStdout();
  worker->onDone();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "task Jhon Smit completed.\n");
}
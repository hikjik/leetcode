#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;int expected;
  };

  std::vector<TestCase> test_cases{
      {.word="abc",.expected=5,},{.word="bza",.expected=7,},{.word="zjpc",.expected=34,},
  };

  for (const auto &[word,expected] : test_cases) {
    const auto actual = Solution::minTimeToType(word);
    REQUIRE(expected == actual);
  }
}

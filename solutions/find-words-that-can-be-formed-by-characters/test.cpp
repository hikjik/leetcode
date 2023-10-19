#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string chars;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"cat", "bt", "hat", "tree"},
          .chars = "atach",
          .expected = 6,
      },
      {
          .words{"hello", "world", "leetcode"},
          .chars = "welldonehoneyr",
          .expected = 10,
      },
  };

  for (const auto &[words, chars, expected] : test_cases) {
    const auto actual = Solution::countCharacters(words, chars);
    REQUIRE(expected == actual);
  }
}

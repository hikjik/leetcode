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

  SECTION("Sorting") {
    for (const auto &[words, chars, expected] : test_cases) {
      const auto actual = sorting::Solution::countCharacters(words, chars);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting") {
    for (const auto &[words, chars, expected] : test_cases) {
      const auto actual = counting::Solution::countCharacters(words, chars);
      REQUIRE(expected == actual);
    }
  }
}

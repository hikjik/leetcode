#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "abacaba",
          .k = 3,
          .expected = 2,
      },
      {
          .word = "abacaba",
          .k = 4,
          .expected = 1,
      },
      {
          .word = "abcbabcd",
          .k = 2,
          .expected = 4,
      },
  };

  for (const auto &[word, k, expected] : test_cases) {
    const auto actual = Solution::minimumTimeToInitialState(word, k);
    REQUIRE(expected == actual);
  }
}

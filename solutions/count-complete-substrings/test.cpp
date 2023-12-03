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
          .word = "rargaa",
          .k = 6,
          .expected = 0,
      },
      {
          .word = "igigee",
          .k = 2,
          .expected = 3,
      },
      {
          .word = "aaabbbccc",
          .k = 3,
          .expected = 6,
      },
  };

  for (const auto &[word, k, expected] : test_cases) {
    const auto actual = Solution::countCompleteSubstrings(word, k);
    REQUIRE(expected == actual);
  }
}

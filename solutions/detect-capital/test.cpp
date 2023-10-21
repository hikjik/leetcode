#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "USA",
          .expected = true,
      },
      {
          .word = "FlaG",
          .expected = false,
      },
  };

  for (const auto &[word, expected] : test_cases) {
    const auto actual = Solution::detectCapitalUse(word);
    REQUIRE(expected == actual);
  }
}

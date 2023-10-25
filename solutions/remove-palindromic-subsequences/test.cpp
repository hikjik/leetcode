#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "ababa",
          .expected = 1,
      },
      {
          .s = "abba",
          .expected = 1,
      },
      {
          .s = "aaaba",
          .expected = 2,
      },
      {
          .s = "abaa",
          .expected = 2,
      },
      {
          .s = "abb",
          .expected = 2,
      },
      {
          .s = "baabb",
          .expected = 2,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::removePalindromeSub(s);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leeetcode",
          .expected = "leetcode",
      },
      {
          .s = "aaabaaaa",
          .expected = "aabaa",
      },
      {
          .s = "aab",
          .expected = "aab",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::makeFancyString(s);
    REQUIRE(expected == actual);
  }
}

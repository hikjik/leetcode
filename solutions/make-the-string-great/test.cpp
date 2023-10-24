#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leEeetcode",
          .expected = "leetcode",
      },
      {
          .s = "abBAcC",
          .expected = "",
      },
      {
          .s = "s",
          .expected = "s",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::makeGood(s);
    REQUIRE(expected == actual);
  }
}

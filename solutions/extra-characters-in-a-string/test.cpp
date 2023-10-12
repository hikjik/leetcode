#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> dictionary;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leetscode",
          .dictionary{"leet", "code", "leetcode"},
          .expected = 1,
      },
      {
          .s = "sayhelloworld",
          .dictionary{"hello", "world"},
          .expected = 3,
      },
  };

  for (const auto &[s, dictionary, expected] : test_cases) {
    const auto actual = Solution::minExtraChar(s, dictionary);
    REQUIRE(expected == actual);
  }
}

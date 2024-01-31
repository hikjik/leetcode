#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcdba",
          .expected = true,
      },
      {
          .s = "aa",
          .expected = true,
      },
      {
          .s = "abcdef",
          .expected = false,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::makePalindrome(s);
    REQUIRE(expected == actual);
  }
}

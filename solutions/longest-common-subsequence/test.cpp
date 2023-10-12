#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string text1;
    std::string text2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .text1 = "abcde",
          .text2 = "ace",
          .expected = 3,
      },
      {
          .text1 = "abc",
          .text2 = "abc",
          .expected = 3,
      },
      {
          .text1 = "abc",
          .text2 = "def",
          .expected = 0,
      },
  };

  for (const auto &[text1, text2, expected] : test_cases) {
    const auto actual = Solution::longestCommonSubsequence(text1, text2);
    REQUIRE(expected == actual);
  }
}

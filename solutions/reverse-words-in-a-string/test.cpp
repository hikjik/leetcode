#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "the sky is blue",
          .expected = "blue is sky the",
      },
      {
          .s = "  hello world  ",
          .expected = "world hello",
      },
      {
          .s = "a good   example",
          .expected = "example good a",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::reverseWords(s);
    REQUIRE(expected == actual);
  }
}

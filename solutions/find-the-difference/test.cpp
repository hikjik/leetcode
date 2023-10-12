#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string t;
    char expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcd",
          .t = "abcde",
          .expected = 'e',
      },
      {
          .s = "",
          .t = "y",
          .expected = 'y',
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::findTheDifference(s, t);
    REQUIRE(expected == actual);
  }
}

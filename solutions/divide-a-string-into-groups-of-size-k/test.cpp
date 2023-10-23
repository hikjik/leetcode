#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    char fill;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcdefghi",
          .k = 3,
          .fill = 'x',
          .expected{"abc", "def", "ghi"},
      },
      {
          .s = "abcdefghij",
          .k = 3,
          .fill = 'x',
          .expected{"abc", "def", "ghi", "jxx"},
      },
  };

  for (const auto &[s, k, fill, expected] : test_cases) {
    const auto actual = Solution::divideString(s, k, fill);
    REQUIRE(expected == actual);
  }
}

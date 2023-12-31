#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aaaa",
          .expected = 2,
      },
      {
          .s = "abcdef",
          .expected = -1,
      },
      {
          .s = "abcaba",
          .expected = 1,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::maximumLength(s);
    REQUIRE(expected == actual);
  }
}

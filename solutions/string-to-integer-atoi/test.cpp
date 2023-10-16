#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "42",
          .expected = 42,
      },
      {
          .s = "   -42",
          .expected = -42,
      },
      {
          .s = "4193 with words",
          .expected = 4193,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::myAtoi(s);
    REQUIRE(expected == actual);
  }
}

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
      {
          .s = "9223372036854775807",
          .expected = 2147483647,
      },
  };

  SECTION("STL") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = stl::Solution::myAtoi(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Iterative") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = iterative::Solution::myAtoi(s);
      REQUIRE(expected == actual);
    }
  }
}

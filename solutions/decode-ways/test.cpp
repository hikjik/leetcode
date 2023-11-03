#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "12",
          .expected = 2,
      },
      {
          .s = "226",
          .expected = 3,
      },
      {
          .s = "06",
          .expected = 0,
      },
  };

  SECTION("Memoization") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = memo::Solution::numDecodings(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = dp::Solution::numDecodings(s);
      REQUIRE(expected == actual);
    }
  }
}

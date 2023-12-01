#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .expected = 5,
      },
      {
          .n = 2,
          .expected = 15,
      },
      {
          .n = 33,
          .expected = 66045,
      },
  };

  SECTION("DP") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::countVowelStrings(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Combinatorics") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = combinatorics::Solution::countVowelStrings(n);
      REQUIRE(expected == actual);
    }
  }
}

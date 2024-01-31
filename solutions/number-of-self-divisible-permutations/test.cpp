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
          .expected = 1,
      },
      {
          .n = 2,
          .expected = 1,
      },
      {
          .n = 3,
          .expected = 3,
      },
  };

  SECTION("Memoization") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = memo::Solution::selfDivisiblePermutationCount(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::selfDivisiblePermutationCount(n);
      REQUIRE(expected == actual);
    }
  }
}

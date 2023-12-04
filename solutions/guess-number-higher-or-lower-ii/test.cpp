#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 10,
          .expected = 16,
      },
      {
          .n = 1,
          .expected = 0,
      },
      {
          .n = 2,
          .expected = 1,
      },
  };

  SECTION("Memoization") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = memo::Solution::getMoneyAmount(n);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[n, expected] : test_cases) {
      const auto actual = dp::Solution::getMoneyAmount(n);
      REQUIRE(expected == actual);
    }
  }
}

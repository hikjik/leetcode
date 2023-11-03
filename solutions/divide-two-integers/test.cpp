#include <catch.hpp>

#include <solution.hpp>

#include <climits>

TEST_CASE("Simple") {
  struct TestCase {
    int dividend;
    int divisor;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .dividend = 10,
          .divisor = 3,
          .expected = 3,
      },
      {
          .dividend = 7,
          .divisor = -3,
          .expected = -2,
      },
      {
          .dividend = INT_MIN,
          .divisor = -1,
          .expected = INT_MAX,
      },
  };

  for (const auto &[dividend, divisor, expected] : test_cases) {
    const auto actual = Solution::divide(dividend, divisor);
    REQUIRE(expected == actual);
  }
}

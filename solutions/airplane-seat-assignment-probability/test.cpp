#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 1,
          .expected = 1.00000,
      },
      {
          .n = 2,
          .expected = 0.50000,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::nthPersonGetsNthSeat(n);
    REQUIRE(expected == Approx(actual));
  }
}

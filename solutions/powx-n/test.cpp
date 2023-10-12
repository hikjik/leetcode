#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    double x;
    int n;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .x = 2.00000,
          .n = 10,
          .expected = 1024.00000,
      },
      {
          .x = 2.10000,
          .n = 3,
          .expected = 9.26100,
      },
      {
          .x = 2.00000,
          .n = -2,
          .expected = 0.25000,
      },
  };

  for (const auto &[x, n, expected] : test_cases) {
    const auto actual = Solution::myPow(x, n);
    REQUIRE(expected == Approx(actual));
  }
}

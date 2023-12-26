#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> primes;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 12,
          .primes{2, 7, 13, 19},
          .expected = 32,
      },
      {
          .n = 1,
          .primes{2, 3, 5},
          .expected = 1,
      },
  };

  for (const auto &[n, primes, expected] : test_cases) {
    const auto actual = Solution::nthSuperUglyNumber(n, primes);
    REQUIRE(expected == actual);
  }
}

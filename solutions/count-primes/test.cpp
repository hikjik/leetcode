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
          .expected = 4,
      },
      {
          .n = 0,
          .expected = 0,
      },
      {
          .n = 1,
          .expected = 0,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::countPrimes(n);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .expected = 4,
      },
      {
          .n = 25,
          .expected = 1389537,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::tribonacci(n);
    REQUIRE(expected == actual);
  }
}

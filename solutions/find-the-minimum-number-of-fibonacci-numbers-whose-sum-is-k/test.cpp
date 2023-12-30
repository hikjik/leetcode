#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .k = 7,
          .expected = 2,
      },
      {
          .k = 10,
          .expected = 2,
      },
      {
          .k = 19,
          .expected = 3,
      },
      {
          .k = 1'000'000'000,
          .expected = 14,
      },
  };

  for (const auto &[k, expected] : test_cases) {
    const auto actual = Solution::findMinFibonacciNumbers(k);
    REQUIRE(expected == actual);
  }
}

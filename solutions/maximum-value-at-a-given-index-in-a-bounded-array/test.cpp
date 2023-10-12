#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int index;
    int maxSum;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .index = 2,
          .maxSum = 6,
          .expected = 2,
      },
      {
          .n = 6,
          .index = 1,
          .maxSum = 10,
          .expected = 3,
      },
  };

  for (const auto &[n, index, maxSum, expected] : test_cases) {
    const auto actual = Solution::maxValue(n, index, maxSum);
    REQUIRE(expected == actual);
  }
}

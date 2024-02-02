#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int low;
    int high;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .low = 100,
          .high = 300,
          .expected{123, 234},
      },
      {
          .low = 1000,
          .high = 13000,
          .expected{1234, 2345, 3456, 4567, 5678, 6789, 12345},
      },
  };

  for (const auto &[low, high, expected] : test_cases) {
    const auto actual = Solution::sequentialDigits(low, high);
    REQUIRE(expected == actual);
  }
}

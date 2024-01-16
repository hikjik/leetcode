#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 12, -5, -6, 50, 3},
          .k = 4,
          .expected = 12.75000,
      },
      {
          .nums{5},
          .k = 1,
          .expected = 5.00000,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::findMaxAverage(nums, k);
    REQUIRE(expected == Approx(actual));
  }
}

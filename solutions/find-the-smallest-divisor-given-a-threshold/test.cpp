#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int threshold;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 5, 9},
          .threshold = 6,
          .expected = 5,
      },
      {
          .nums{44, 22, 33, 11, 1},
          .threshold = 5,
          .expected = 44,
      },
  };

  for (const auto &[nums, threshold, expected] : test_cases) {
    const auto actual = Solution::smallestDivisor(nums, threshold);
    REQUIRE(expected == actual);
  }
}

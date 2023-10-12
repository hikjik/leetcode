#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1},
          .k = 0,
          .expected = 0,
      },
      {
          .nums{0, 10},
          .k = 2,
          .expected = 6,
      },
      {
          .nums{1, 3, 6},
          .k = 3,
          .expected = 3,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::smallestRangeII(nums, k);
    REQUIRE(expected == actual);
  }
}

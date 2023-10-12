#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, -1, -3, 5, 3, 6, 7},
          .k = 3,
          .expected{3, 3, 5, 5, 6, 7},
      },
      {
          .nums{1},
          .k = 1,
          .expected{1},
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::maxSlidingWindow(nums, k);
    REQUIRE(expected == actual);
  }
}

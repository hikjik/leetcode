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
          .nums{3, 2, 1, 5, 6, 4},
          .k = 2,
          .expected = 5,
      },
      {
          .nums{3, 2, 3, 1, 2, 4, 5, 5, 6},
          .k = 4,
          .expected = 4,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::findKthLargest(nums, k);
    REQUIRE(expected == actual);
  }
}

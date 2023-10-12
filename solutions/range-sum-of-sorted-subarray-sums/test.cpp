#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int n;
    int left;
    int right;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .n = 4,
          .left = 1,
          .right = 5,
          .expected = 13,
      },
      {
          .nums{1, 2, 3, 4},
          .n = 4,
          .left = 3,
          .right = 4,
          .expected = 6,
      },
      {
          .nums{1, 2, 3, 4},
          .n = 4,
          .left = 1,
          .right = 10,
          .expected = 50,
      },
  };

  for (const auto &[nums, n, left, right, expected] : test_cases) {
    const auto actual = Solution::rangeSum(nums, n, left, right);
    REQUIRE(expected == actual);
  }
}

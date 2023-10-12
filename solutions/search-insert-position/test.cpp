#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 5, 6},
          .target = 5,
          .expected = 2,
      },
      {
          .nums{1, 3, 5, 6},
          .target = 2,
          .expected = 1,
      },
      {
          .nums{1, 3, 5, 6},
          .target = 7,
          .expected = 4,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::searchInsert(nums, target);
    REQUIRE(expected == actual);
  }
}

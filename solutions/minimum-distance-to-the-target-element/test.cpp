#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    int start;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5},
          .target = 5,
          .start = 3,
          .expected = 1,
      },
      {
          .nums{1},
          .target = 1,
          .start = 0,
          .expected = 0,
      },
      {
          .nums{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
          .target = 1,
          .start = 0,
          .expected = 0,
      },
  };

  for (const auto &[nums, target, start, expected] : test_cases) {
    const auto actual = Solution::getMinDistance(nums, target, start);
    REQUIRE(expected == actual);
  }
}

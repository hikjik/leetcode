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
          .nums{-1, 0, 3, 5, 9, 12},
          .target = 9,
          .expected = 4,
      },
      {
          .nums{-1, 0, 3, 5, 9, 12},
          .target = 2,
          .expected = -1,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::search(nums, target);
    REQUIRE(expected == actual);
  }
}

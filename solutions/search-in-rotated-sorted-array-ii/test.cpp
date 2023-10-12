#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 5, 6, 0, 0, 1, 2},
          .target = 0,
          .expected = true,
      },
      {
          .nums{2, 5, 6, 0, 0, 1, 2},
          .target = 3,
          .expected = false,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::search(nums, target);
    REQUIRE(expected == actual);
  }
}

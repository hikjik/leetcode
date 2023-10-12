#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 1, 1, 4},
          .expected = true,
      },
      {
          .nums{3, 2, 1, 0, 4},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::canJump(nums);
    REQUIRE(expected == actual);
  }
}

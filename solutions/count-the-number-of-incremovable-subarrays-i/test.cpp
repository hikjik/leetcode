#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .expected = 10,
      },
      {
          .nums{6, 5, 7, 8},
          .expected = 7,
      },
      {
          .nums{8, 7, 6, 6},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::incremovableSubarrayCount(nums);
    REQUIRE(expected == actual);
  }
}

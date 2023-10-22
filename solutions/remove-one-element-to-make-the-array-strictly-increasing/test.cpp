#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 10, 5, 7},
          .expected = true,
      },
      {
          .nums{2, 3, 1, 2},
          .expected = false,
      },
      {
          .nums{1, 1, 1},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::canBeIncreasing(nums);
    REQUIRE(expected == actual);
  }
}

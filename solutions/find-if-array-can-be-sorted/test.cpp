#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{8, 4, 2, 30, 15},
          .expected = true,
      },
      {
          .nums{1, 2, 3, 4, 5},
          .expected = true,
      },
      {
          .nums{3, 16, 8, 4, 2},
          .expected = false,
      },
      {
          .nums{4, 3, 2},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::canSortArray(nums);
    REQUIRE(expected == actual);
  }
}

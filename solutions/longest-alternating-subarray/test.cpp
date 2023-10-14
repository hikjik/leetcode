#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 4, 3, 4},
          .expected = 4,
      },
      {
          .nums{4, 5, 6},
          .expected = 2,
      },
      {
          .nums{1, 2},
          .expected = 2,
      },
      {
          .nums{1, 1},
          .expected = -1,
      },
      {
          .nums{21, 9, 5},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::alternatingSubarray(nums);
    REQUIRE(expected == actual);
  }
}

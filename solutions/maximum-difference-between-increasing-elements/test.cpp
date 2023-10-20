#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{7, 1, 5, 4},
          .expected = 4,
      },
      {
          .nums{9, 4, 3, 2},
          .expected = -1,
      },
      {
          .nums{1, 5, 2, 10},
          .expected = 9,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maximumDifference(nums);
    REQUIRE(expected == actual);
  }
}

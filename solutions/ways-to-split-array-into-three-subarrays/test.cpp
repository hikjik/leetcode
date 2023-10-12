#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 1},
          .expected = 1,
      },
      {
          .nums{1, 2, 2, 2, 5, 0},
          .expected = 3,
      },
      {
          .nums{3, 2, 1},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::waysToSplit(nums);
    REQUIRE(expected == actual);
  }
}

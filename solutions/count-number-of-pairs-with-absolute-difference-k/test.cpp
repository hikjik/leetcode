#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 2, 1},
          .k = 1,
          .expected = 4,
      },
      {
          .nums{1, 3},
          .k = 3,
          .expected = 0,
      },
      {
          .nums{3, 2, 1, 5, 4},
          .k = 2,
          .expected = 3,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::countKDifference(nums, k);
    REQUIRE(expected == actual);
  }
}

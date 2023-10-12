#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 7, 3, 6, 5, 6},
          .expected = 3,
      },
      {
          .nums{1, 2, 3},
          .expected = -1,
      },
      {
          .nums{2, 1, -1},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::pivotIndex(nums);
    REQUIRE(expected == actual);
  }
}

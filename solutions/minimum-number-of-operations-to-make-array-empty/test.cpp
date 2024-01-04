#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 3, 2, 2, 4, 2, 3, 4},
          .expected = 4,
      },
      {
          .nums{2, 1, 2, 2, 3, 3},
          .expected = -1,
      },
      {
          .nums{2, 2, 2, 2, 2, 2, 2},
          .expected = 3,
      },
      {
          .nums{14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14,
                14, 12, 12},
          .expected = 7,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums);
    REQUIRE(expected == actual);
  }
}

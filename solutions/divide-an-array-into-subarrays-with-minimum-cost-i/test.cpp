#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 12},
          .expected = 6,
      },
      {
          .nums{5, 4, 3},
          .expected = 12,
      },
      {
          .nums{10, 3, 1, 1},
          .expected = 12,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimumCost(nums);
    REQUIRE(expected == actual);
  }
}

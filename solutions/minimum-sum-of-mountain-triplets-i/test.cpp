#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{8, 6, 1, 5, 3},
          .expected = 9,
      },
      {
          .nums{5, 4, 8, 7, 10, 2},
          .expected = 13,
      },
      {
          .nums{6, 5, 4, 3, 4, 5},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimumSum(nums);
    REQUIRE(expected == actual);
  }
}

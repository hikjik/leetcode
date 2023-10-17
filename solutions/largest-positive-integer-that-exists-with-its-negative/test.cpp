#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-1, 2, -3, 3},
          .expected = 3,
      },
      {
          .nums{-1, 10, 6, 7, -7, 1},
          .expected = 7,
      },
      {
          .nums{-10, 8, 6, 7, -2, -3},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findMaxK(nums);
    REQUIRE(expected == actual);
  }
}

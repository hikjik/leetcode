#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 6, 1, 0},
          .expected = 1,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::dominantIndex(nums);
    REQUIRE(expected == actual);
  }
}

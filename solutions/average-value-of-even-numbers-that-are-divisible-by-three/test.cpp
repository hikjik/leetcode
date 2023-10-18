#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 6, 10, 12, 15},
          .expected = 9,
      },
      {
          .nums{1, 2, 4, 7, 10},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::averageValue(nums);
    REQUIRE(expected == actual);
  }
}

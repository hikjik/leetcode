#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 2, 3, 1},
          .expected = 2,
      },
      {
          .nums{1, 2, 2, 3, 1, 4, 2},
          .expected = 6,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findShortestSubArray(nums);
    REQUIRE(expected == actual);
  }
}

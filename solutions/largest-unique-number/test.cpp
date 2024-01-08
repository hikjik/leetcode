#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 7, 3, 9, 4, 9, 8, 3, 1},
          .expected = 8,
      },
      {
          .nums{9, 9, 8, 8},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::largestUniqueNumber(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 6, 2, 7, 4},
          .expected = 34,
      },
      {
          .nums{4, 2, 5, 9, 7, 4, 8},
          .expected = 64,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxProductDifference(nums);
    REQUIRE(expected == actual);
  }
}

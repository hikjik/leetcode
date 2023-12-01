#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 13, 10, 12, 31},
          .expected = 6,
      },
      {
          .nums{2, 2, 2},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::countDistinctIntegers(nums);
    REQUIRE(expected == actual);
  }
}

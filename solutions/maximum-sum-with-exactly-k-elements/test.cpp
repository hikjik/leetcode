#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5},
          .k = 3,
          .expected = 18,
      },
      {
          .nums{5, 5, 5},
          .k = 2,
          .expected = 11,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::maximizeSum(nums, k);
    REQUIRE(expected == actual);
  }
}

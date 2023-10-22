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
          .nums{5, 5, 4, 5, 4, 1, 1, 1},
          .k = 0,
          .expected = 20,
      },
      {
          .nums{6569, 9667, 3148, 7698, 1622, 2194, 793, 9041, 1670, 1872},
          .k = 5,
          .expected = 9732,
      },
      {
          .nums{1, 4, 3, 7, 4, 5},
          .k = 3,
          .expected = 15,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::maximumScore(nums, k);
    REQUIRE(expected == actual);
  }
}

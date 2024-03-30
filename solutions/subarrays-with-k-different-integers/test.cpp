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
          .nums{1, 2, 1, 2, 3},
          .k = 2,
          .expected = 7,
      },
      {
          .nums{1, 2, 1, 3, 4},
          .k = 3,
          .expected = 3,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::subarraysWithKDistinct(nums, k);
    REQUIRE(expected == actual);
  }
}

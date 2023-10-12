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
          .nums{1, 1, 1},
          .k = 2,
          .expected = 2,
      },
      {
          .nums{1, 2, 3},
          .k = 3,
          .expected = 2,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::subarraySum(nums, k);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 2, 3, 3},
          .k = 2,
          .expected = 6,
      },
      {
          .nums{1, 4, 2, 1},
          .k = 3,
          .expected = 0,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::countSubarrays(nums, k);
    REQUIRE(expected == actual);
  }
}

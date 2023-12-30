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
          .nums{9, 3, 1, 2, 6, 3},
          .k = 3,
          .expected = 4,
      },
      {
          .nums{4},
          .k = 7,
          .expected = 0,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::subarrayGCD(nums, k);
    REQUIRE(expected == actual);
  }
}

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
          .nums{2, 1, 3, 4},
          .k = 1,
          .expected = 2,
      },
      {
          .nums{2, 0, 2, 0},
          .k = 0,
          .expected = 0,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums, k);
    REQUIRE(expected == actual);
  }
}

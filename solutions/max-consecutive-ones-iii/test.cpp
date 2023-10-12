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
          .nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
          .k = 2,
          .expected = 6,
      },
      {
          .nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
          .k = 3,
          .expected = 10,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::longestOnes(nums, k);
    REQUIRE(expected == actual);
  }
}

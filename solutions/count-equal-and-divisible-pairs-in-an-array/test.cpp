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
          .nums{3, 1, 2, 2, 2, 1, 3},
          .k = 2,
          .expected = 4,
      },
      {
          .nums{1, 2, 3, 4},
          .k = 1,
          .expected = 0,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::countPairs(nums, k);
    REQUIRE(expected == actual);
  }
}

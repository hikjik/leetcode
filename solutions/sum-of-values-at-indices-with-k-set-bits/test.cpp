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
          .nums{5, 10, 1, 5, 2},
          .k = 1,
          .expected = 13,
      },
      {
          .nums{4, 3, 2, 1},
          .k = 2,
          .expected = 1,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::sumIndicesWithKSetBits(nums, k);
    REQUIRE(expected == actual);
  }
}

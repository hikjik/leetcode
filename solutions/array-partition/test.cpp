#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 4, 3, 2},
          .expected = 4,
      },
      {
          .nums{6, 2, 6, 5, 1, 2},
          .expected = 9,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::arrayPairSum(nums);
    REQUIRE(expected == actual);
  }
}

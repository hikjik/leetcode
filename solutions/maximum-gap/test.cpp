#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 6, 9, 1},
          .expected = 3,
      },
      {
          .nums{10},
          .expected = 0,
      },
      {
          .nums{1, 10000000},
          .expected = 9999999,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maximumGap(nums);
    REQUIRE(expected == actual);
  }
}

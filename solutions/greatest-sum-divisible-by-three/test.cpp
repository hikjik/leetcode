#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 6, 5, 1, 8},
          .expected = 18,
      },
      {
          .nums{4},
          .expected = 0,
      },
      {
          .nums{1, 2, 3, 4, 4},
          .expected = 12,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxSumDivThree(nums);
    REQUIRE(expected == actual);
  }
}

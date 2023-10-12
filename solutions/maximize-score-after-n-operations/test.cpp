#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2},
          .expected = 1,
      },
      {
          .nums{3, 4, 6, 8},
          .expected = 11,
      },
      {
          .nums{1, 2, 3, 4, 5, 6},
          .expected = 14,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxScore(nums);
    REQUIRE(expected == actual);
  }
}

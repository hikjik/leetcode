#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 2, 1, 4},
          .expected = 2,
      },
      {
          .nums{1, 2},
          .expected = -1,
      },
      {
          .nums{2, 1, 3},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findNonMinOrMax(nums);
    REQUIRE(expected == actual);
  }
}

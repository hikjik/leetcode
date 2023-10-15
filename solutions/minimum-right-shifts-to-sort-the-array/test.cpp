#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 4, 5, 1, 2},
          .expected = 2,
      },
      {
          .nums{1, 3, 5},
          .expected = 0,
      },
      {
          .nums{2, 1, 4},
          .expected = -1,
      },
      {
          .nums{2},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimumRightShifts(nums);
    REQUIRE(expected == actual);
  }
}

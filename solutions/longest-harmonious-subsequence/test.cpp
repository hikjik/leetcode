#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 2, 2, 5, 2, 3, 7},
          .expected = 5,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = 2,
      },
      {
          .nums{1, 1, 1, 1},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findLHS(nums);
    REQUIRE(expected == actual);
  }
}

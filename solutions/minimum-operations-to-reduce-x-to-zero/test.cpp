#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int x;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 4, 2, 3},
          .x = 5,
          .expected = 2,
      },
      {
          .nums{5, 6, 7, 8, 9},
          .x = 4,
          .expected = -1,
      },
      {
          .nums{3, 2, 20, 1, 1, 3},
          .x = 10,
          .expected = 5,
      },
  };

  for (const auto &[nums, x, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums, x);
    REQUIRE(expected == actual);
  }
}

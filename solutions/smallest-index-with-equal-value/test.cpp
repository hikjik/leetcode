#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 2},
          .expected = 0,
      },
      {
          .nums{4, 3, 2, 1},
          .expected = 2,
      },
      {
          .nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::smallestEqual(nums);
    REQUIRE(expected == actual);
  }
}

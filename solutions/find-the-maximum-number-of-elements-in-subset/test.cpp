#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 2, 4},
          .expected = 1,
      },
      {
          .nums{1, 1, 1},
          .expected = 3,
      },
      {
          .nums{1, 1, 1, 1},
          .expected = 3,
      },
      {
          .nums{5, 4, 1, 2, 2},
          .expected = 3,
      },
      {
          .nums{1, 16, 49, 16, 121},
          .expected = 1,
      },
      {
          .nums{14, 14, 196, 196, 38416, 38416},
          .expected = 5,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maximumLength(nums);
    REQUIRE(expected == actual);
  }
}

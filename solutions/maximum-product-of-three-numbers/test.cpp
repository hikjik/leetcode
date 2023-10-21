#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-100, -98, -1, 2, 3, 4},
          .expected = 39200,
      },
      {
          .nums{-100, -2, -3, 1},
          .expected = 300,
      },
      {
          .nums{1, 2, 3},
          .expected = 6,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = 24,
      },
      {
          .nums{-1, -2, -3},
          .expected = -6,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maximumProduct(nums);
    REQUIRE(expected == actual);
  }
}

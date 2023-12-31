#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5},
          .expected = true,
      },
      {
          .nums{2, 4, 8, 16},
          .expected = true,
      },
      {
          .nums{1, 3, 5, 7, 9},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::hasTrailingZeros(nums);
    REQUIRE(expected == actual);
  }
}

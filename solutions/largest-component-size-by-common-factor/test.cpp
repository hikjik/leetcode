#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 6, 7, 4, 12, 21, 39},
          .expected = 8,
      },
      {
          .nums{4, 6, 15, 35},
          .expected = 4,
      },
      {
          .nums{20, 50, 9, 63},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::largestComponentSize(nums);
    REQUIRE(expected == actual);
  }
}

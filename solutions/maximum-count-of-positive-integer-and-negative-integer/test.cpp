#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-2, -1, -1, 1, 2, 3},
          .expected = 3,
      },
      {
          .nums{-3, -2, -1, 0, 0, 1, 2},
          .expected = 3,
      },
      {
          .nums{5, 20, 66, 1314},
          .expected = 4,
      },
      {
          .nums{-5, -20, -66, -1314},
          .expected = 4,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maximumCount(nums);
    REQUIRE(expected == actual);
  }
}

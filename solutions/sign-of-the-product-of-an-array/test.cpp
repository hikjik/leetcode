#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-1, -2, -3, -4, 3, 2, 1},
          .expected = 1,
      },
      {
          .nums{1, 5, 0, 2, -3},
          .expected = 0,
      },
      {
          .nums{-1, 1, -1, 1, -1},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::arraySign(nums);
    REQUIRE(expected == actual);
  }
}

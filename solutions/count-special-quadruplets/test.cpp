#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 6},
          .expected = 1,
      },
      {
          .nums{3, 3, 6, 4, 5},
          .expected = 0,
      },
      {
          .nums{1, 1, 1, 3, 5},
          .expected = 4,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::countQuadruplets(nums);
    REQUIRE(expected == actual);
  }
}

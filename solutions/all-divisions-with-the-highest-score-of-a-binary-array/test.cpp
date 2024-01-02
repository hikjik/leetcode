#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 0, 1, 0},
          .expected{2, 4},
      },
      {
          .nums{0, 0, 0},
          .expected{3},
      },
      {
          .nums{1, 1},
          .expected{0},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxScoreIndices(nums);
    REQUIRE(expected == actual);
  }
}

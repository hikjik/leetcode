#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 2, 2, 2, 3},
          .expected{3, 1, 1, 2, 2, 2},
      },
      {
          .nums{2, 3, 1, 3, 2},
          .expected{1, 3, 3, 2, 2},
      },
      {
          .nums{-1, 1, -6, 4, 5, -6, 1, 4, 1},
          .expected{5, -1, 4, 4, -6, -6, 1, 1, 1},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::frequencySort(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 6},
          .expected = true,
      },
      {
          .nums{3, 9, 5},
          .expected = false,
      },
      {
          .nums{4, 3, 12, 8},
          .expected = true,
      },
      {
          .nums{1, 1},
          .expected = false,
      },
      {
          .nums{1},
          .expected = true,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::canTraverseAllPairs(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> pattern;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5, 6},
          .pattern{1, 1},
          .expected = 4,
      },
      {
          .nums{1, 4, 4, 1, 3, 5, 5, 3},
          .pattern{1, 0, -1},
          .expected = 2,
      },
  };

  for (const auto &[nums, pattern, expected] : test_cases) {
    const auto actual = Solution::countMatchingSubarrays(nums, pattern);
    REQUIRE(expected == actual);
  }
}

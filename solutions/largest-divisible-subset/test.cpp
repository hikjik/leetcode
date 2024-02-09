#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3},
          .expected{1, 2},
      },
      {
          .nums{1, 2, 4, 8},
          .expected{1, 2, 4, 8},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::largestDivisibleSubset(nums);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}

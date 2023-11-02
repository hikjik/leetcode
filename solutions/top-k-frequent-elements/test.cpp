#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 1, 2, 2, 3},
          .k = 2,
          .expected{1, 2},
      },
      {
          .nums{1},
          .k = 1,
          .expected{1},
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::topKFrequent(nums, k);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}

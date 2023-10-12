#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 2},
          .expected{{1, 1, 2}, {1, 2, 1}, {2, 1, 1}},
      },
      {
          .nums{1, 2, 3},
          .expected{
              {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::permuteUnique(nums);
    REQUIRE(expected == actual);
  }
}

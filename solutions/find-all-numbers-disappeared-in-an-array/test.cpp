#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 3, 2, 7, 8, 2, 3, 1},
          .expected{5, 6},
      },
      {
          .nums{1, 1},
          .expected{2},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findDisappearedNumbers(nums);
    REQUIRE(expected == actual);
  }
}

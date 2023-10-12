#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{10, 6, 5, 8},
          .expected{8, 10},
      },
      {
          .nums{1, 3, 5, 3},
          .expected{1, 5},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    auto actual = Solution::findLonely(nums);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
}

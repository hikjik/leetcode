#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3},
          .expected{{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}},
      },
      {
          .nums{0},
          .expected{{}, {0}},
      },
  };

  for (auto &[nums, expected] : test_cases) {
    auto actual = Solution::subsets(nums);
    std::sort(expected.begin(), expected.end());
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}},
          .expected{3, 4},
      },
      {
          .nums{{1, 2, 3}, {4, 5, 6}},
          .expected{},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::intersection(nums);
    REQUIRE(expected == actual);
  }
}

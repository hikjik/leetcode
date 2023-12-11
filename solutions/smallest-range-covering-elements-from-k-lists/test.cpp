#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}},
          .expected{20, 24},
      },
      {
          .nums{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}},
          .expected{1, 1},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::smallestRange(nums);
    REQUIRE(expected[1] - expected[0] == actual[1] - actual[0]);
  }
}

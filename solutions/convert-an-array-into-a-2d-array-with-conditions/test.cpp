#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .expected{{1, 2, 3, 4}},
      },
      {
          .nums{1, 3, 4, 1, 2, 3, 1},
          .expected{{1, 3, 4, 2}, {1, 3}, {1}},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findMatrix(nums);
    REQUIRE(expected == actual);
  }
}

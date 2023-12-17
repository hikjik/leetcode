#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 4, 8, 7, 9, 3, 5, 1},
          .k = 2,
          .expected{{1, 1, 3}, {3, 4, 5}, {7, 8, 9}},
      },
      {
          .nums{1, 3, 3, 2, 7, 3},
          .k = 3,
          .expected{},
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::divideArray(nums, k);
    REQUIRE(expected == actual);
  }
}

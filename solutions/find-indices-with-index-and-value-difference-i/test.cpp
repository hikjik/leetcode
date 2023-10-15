#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int indexDifference;
    int valueDifference;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 1, 4, 1},
          .indexDifference = 2,
          .valueDifference = 4,
          .expected{0, 3},
      },
      {
          .nums{2, 1},
          .indexDifference = 0,
          .valueDifference = 0,
          .expected{0, 0},
      },
      {
          .nums{1, 2, 3},
          .indexDifference = 2,
          .valueDifference = 4,
          .expected{-1, -1},
      },
  };

  for (const auto &[nums, indexDifference, valueDifference, expected] :
       test_cases) {
    const auto actual =
        Solution::findIndices(nums, indexDifference, valueDifference);
    REQUIRE(expected == actual);
  }
}

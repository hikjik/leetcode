#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> changeIndices;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3},
          .changeIndices{1, 1, 1, 2, 1, 1, 1},
          .expected = 6,
      },
      {
          .nums{2, 2, 0},
          .changeIndices{2, 2, 2, 2, 3, 2, 2, 1},
          .expected = 8,
      },
      {
          .nums{0, 1},
          .changeIndices{2, 2, 2},
          .expected = -1,
      },
  };

  for (const auto &[nums, changeIndices, expected] : test_cases) {
    const auto actual =
        Solution::earliestSecondToMarkIndices(nums, changeIndices);
    REQUIRE(expected == actual);
  }
}

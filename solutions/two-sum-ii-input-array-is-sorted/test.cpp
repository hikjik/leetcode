#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> numbers;
    int target;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .numbers{2, 7, 11, 15},
          .target = 9,
          .expected{1, 2},
      },
      {
          .numbers{2, 3, 4},
          .target = 6,
          .expected{1, 3},
      },
      {
          .numbers{-1, 0},
          .target = -1,
          .expected{1, 2},
      },
  };

  for (const auto &[numbers, target, expected] : test_cases) {
    const auto actual = Solution::twoSum(numbers, target);
    REQUIRE(expected == actual);
  }
}

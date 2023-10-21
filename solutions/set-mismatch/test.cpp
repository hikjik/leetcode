#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{7, 4, 2, 3, 4, 5, 1},
          .expected{4, 6},
      },
      {
          .nums{1, 2, 2, 4},
          .expected{2, 3},
      },
      {
          .nums{1, 1},
          .expected{1, 2},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findErrorNums(nums);
    REQUIRE(expected == actual);
  }
}

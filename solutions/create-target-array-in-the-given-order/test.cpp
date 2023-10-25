#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> index;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 2, 3, 4},
          .index{0, 1, 2, 2, 1},
          .expected{0, 4, 1, 3, 2},
      },
      {
          .nums{1, 2, 3, 4, 0},
          .index{0, 1, 2, 3, 0},
          .expected{0, 1, 2, 3, 4},
      },
      {
          .nums{1},
          .index{0},
          .expected{1},
      },
  };

  for (const auto &[nums, index, expected] : test_cases) {
    const auto actual = Solution::createTargetArray(nums, index);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 5, 2, 3},
          .target = 2,
          .expected{1, 2},
      },
      {
          .nums{1, 2, 5, 2, 3},
          .target = 3,
          .expected{3},
      },
      {
          .nums{1, 2, 5, 2, 3},
          .target = 5,
          .expected{4},
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::targetIndices(nums, target);
    REQUIRE(expected == actual);
  }
}

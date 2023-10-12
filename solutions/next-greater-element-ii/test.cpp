#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 1},
          .expected{2, -1, 2},
      },
      {
          .nums{1, 2, 3, 4, 3},
          .expected{2, 3, 4, -1, 4},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::nextGreaterElements(nums);
    REQUIRE(expected == actual);
  }
}

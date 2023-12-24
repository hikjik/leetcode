#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 4, 2, 3},
          .expected{3, 2, 5, 4},
      },
      {
          .nums{2, 5},
          .expected{5, 2},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::numberGame(nums);
    REQUIRE(expected == actual);
  }
}

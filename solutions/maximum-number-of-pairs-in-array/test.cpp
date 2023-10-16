#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 2, 1, 3, 2, 2},
          .expected{3, 1},
      },
      {
          .nums{1, 1},
          .expected{1, 0},
      },
      {
          .nums{0},
          .expected{0, 1},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::numberOfPairs(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 1, 3, 2, 5},
          .expected{3, 5},
      },
      {
          .nums{-1, 0},
          .expected{-1, 0},
      },
      {
          .nums{0, 1},
          .expected{0, 1},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    auto actual = Solution::singleNumber(nums);
    std::sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
}

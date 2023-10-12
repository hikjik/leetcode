#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 2},
          .expected = 3,
      },
      {
          .nums{1, 2, 3, 1},
          .expected = 4,
      },
      {
          .nums{1, 2, 3},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::rob(nums);
    REQUIRE(expected == actual);
  }
}

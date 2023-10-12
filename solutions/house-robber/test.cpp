#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 1},
          .expected = 4,
      },
      {
          .nums{2, 7, 9, 3, 1},
          .expected = 12,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::rob(nums);
    REQUIRE(expected == actual);
  }
}

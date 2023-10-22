#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 1},
          .expected = 3,
      },
      {
          .nums{1, 5, 2, 4, 1},
          .expected = 14,
      },
      {
          .nums{8},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums);
    REQUIRE(expected == actual);
  }
}

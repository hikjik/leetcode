#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 6, 3, 4},
          .expected = 4,
      },
      {
          .nums{2, 10, 6, 14},
          .expected = -1,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = 3,
      },
      {
          .nums{6, 10, 15},
          .expected = 4,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums);
    REQUIRE(expected == actual);
  }
}

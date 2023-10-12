#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 2, 5, 3},
          .expected = 0,
      },
      {
          .nums{1, 2, 3, 5, 6},
          .expected = 1,
      },
      {
          .nums{1, 10, 100, 1000},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums);
    REQUIRE(expected == actual);
  }
}

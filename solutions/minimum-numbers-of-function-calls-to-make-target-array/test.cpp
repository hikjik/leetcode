#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1000000000},
          .expected = 42,
      },
      {
          .nums{1, 5},
          .expected = 5,
      },
      {
          .nums{2, 2},
          .expected = 3,
      },
      {
          .nums{4, 2, 5},
          .expected = 6,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums);
    REQUIRE(expected == actual);
  }
}

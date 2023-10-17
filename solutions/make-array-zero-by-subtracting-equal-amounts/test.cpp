#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 5, 0, 3, 5},
          .expected = 3,
      },
      {
          .nums{0},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimumOperations(nums);
    REQUIRE(expected == actual);
  }
}

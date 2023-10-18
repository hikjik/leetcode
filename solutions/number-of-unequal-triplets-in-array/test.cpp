#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 4, 2, 4, 3},
          .expected = 3,
      },
      {
          .nums{1, 1, 1, 1, 1},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::unequalTriplets(nums);
    REQUIRE(expected == actual);
  }
}
#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int diff;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 4, 6, 7, 10},
          .diff = 3,
          .expected = 2,
      },
      {
          .nums{4, 5, 6, 7, 8, 9},
          .diff = 2,
          .expected = 2,
      },
  };

  for (const auto &[nums, diff, expected] : test_cases) {
    const auto actual = Solution::arithmeticTriplets(nums, diff);
    REQUIRE(expected == actual);
  }
}

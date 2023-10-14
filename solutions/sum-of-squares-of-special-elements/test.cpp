#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .expected = 21,
      },
      {
          .nums{2, 7, 1, 19, 18, 3},
          .expected = 63,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::sumOfSquares(nums);
    REQUIRE(expected == actual);
  }
}

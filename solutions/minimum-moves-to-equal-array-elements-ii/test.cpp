#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3},
          .expected = 2,
      },
      {
          .nums{1, 10, 2, 9},
          .expected = 16,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minMoves2(nums);
    REQUIRE(expected == actual);
  }
}

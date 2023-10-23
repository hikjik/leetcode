#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int original;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 3, 6, 1, 12},
          .original = 3,
          .expected = 24,
      },
      {
          .nums{2, 7, 9},
          .original = 4,
          .expected = 4,
      },
  };

  for (const auto &[nums, original, expected] : test_cases) {
    const auto actual = Solution::findFinalValue(nums, original);
    REQUIRE(expected == actual);
  }
}

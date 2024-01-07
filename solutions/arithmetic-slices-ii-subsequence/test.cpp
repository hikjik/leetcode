#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 4, 6, 8, 10},
          .expected = 7,
      },
      {
          .nums{7, 7, 7, 7, 7},
          .expected = 16,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::numberOfArithmeticSlices(nums);
    REQUIRE(expected == actual);
  }
}

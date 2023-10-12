#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, -2, 4},
          .expected = 6,
      },
      {
          .nums{-2, 0, -1},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxProduct(nums);
    REQUIRE(expected == actual);
  }
}

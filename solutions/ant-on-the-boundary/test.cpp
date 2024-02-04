#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, -5},
          .expected = 1,
      },
      {
          .nums{3, 2, -3, -4},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::returnToBoundaryCount(nums);
    REQUIRE(expected == actual);
  }
}

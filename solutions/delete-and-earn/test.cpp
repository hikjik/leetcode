#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 4, 2},
          .expected = 6,
      },
      {
          .nums{2, 2, 3, 3, 3, 4},
          .expected = 9,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::deleteAndEarn(nums);
    REQUIRE(expected == actual);
  }
}

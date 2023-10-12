#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 5},
          .expected = 1,
      },
      {
          .nums{2, 2, 2, 0, 1},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findMin(nums);
    REQUIRE(expected == actual);
  }
}

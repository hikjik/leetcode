#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 3, 2, 6},
          .expected = 26,
      },
      {
          .nums{100},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxRotateFunction(nums);
    REQUIRE(expected == actual);
  }
}

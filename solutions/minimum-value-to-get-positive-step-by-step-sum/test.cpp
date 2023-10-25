#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-3, 2, -3, 4, 2},
          .expected = 5,
      },
      {
          .nums{1, 2},
          .expected = 1,
      },
      {
          .nums{1, -2, -3},
          .expected = 5,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minStartValue(nums);
    REQUIRE(expected == actual);
  }
}

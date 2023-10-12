#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 2, 3},
          .expected = true,
      },
      {
          .nums{6, 5, 4, 4},
          .expected = true,
      },
      {
          .nums{1, 3, 2},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::isMonotonic(nums);
    REQUIRE(expected == actual);
  }
}

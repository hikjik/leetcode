#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5},
          .expected = true,
      },
      {
          .nums{5, 4, 3, 2, 1},
          .expected = false,
      },
      {
          .nums{2, 1, 5, 0, 4, 6},
          .expected = true,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::increasingTriplet(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 1, 1, 3},
          .expected = 4,
      },
      {
          .nums{1, 1, 1, 1},
          .expected = 6,
      },
      {
          .nums{1, 2, 3},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::numIdenticalPairs(nums);
    REQUIRE(expected == actual);
  }
}

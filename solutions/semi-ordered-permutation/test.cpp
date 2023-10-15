#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 1, 4, 3},
          .expected = 2,
      },
      {
          .nums{2, 4, 1, 3},
          .expected = 3,
      },
      {
          .nums{1, 3, 4, 2, 5},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::semiOrderedPermutation(nums);
    REQUIRE(expected == actual);
  }
}

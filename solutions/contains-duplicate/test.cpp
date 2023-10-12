#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 1},
          .expected = true,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = false,
      },
      {
          .nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2},
          .expected = true,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::containsDuplicate(nums);
    REQUIRE(expected == actual);
  }
}

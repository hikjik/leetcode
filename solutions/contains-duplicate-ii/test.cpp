#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 1},
          .k = 3,
          .expected = true,
      },
      {
          .nums{1, 0, 1, 1},
          .k = 1,
          .expected = true,
      },
      {
          .nums{1, 2, 3, 1, 2, 3},
          .k = 2,
          .expected = false,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::containsNearbyDuplicate(nums, k);
    REQUIRE(expected == actual);
  }
}

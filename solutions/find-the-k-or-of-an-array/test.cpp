#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{7, 12, 9, 8, 9, 15},
          .k = 4,
          .expected = 9,
      },
      {
          .nums{2, 12, 1, 11, 4, 5},
          .k = 6,
          .expected = 0,
      },
      {
          .nums{10, 8, 5, 9, 11, 6, 8},
          .k = 1,
          .expected = 15,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::findKOr(nums, k);
    REQUIRE(expected == actual);
  }
}

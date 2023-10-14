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
          .nums{3, 1, 5, 4, 2},
          .k = 2,
          .expected = 4,
      },
      {
          .nums{3, 1, 5, 4, 2},
          .k = 5,
          .expected = 5,
      },
      {
          .nums{3, 2, 5, 3, 1},
          .k = 3,
          .expected = 4,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums, k);
    REQUIRE(expected == actual);
  }
}

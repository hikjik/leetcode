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
          .nums{3, 5, 3, 2, 7},
          .k = 2,
          .expected = 3,
      },
      {
          .nums{7, 3, 15, 14, 2, 8},
          .k = 4,
          .expected = 2,
      },
      {
          .nums{10, 7, 10, 3, 9, 14, 9, 4},
          .k = 1,
          .expected = 15,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::minOrAfterOperations(nums, k);
    REQUIRE(expected == actual);
  }
}

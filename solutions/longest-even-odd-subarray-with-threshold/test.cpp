#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int threshold;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 10, 3},
          .threshold = 10,
          .expected = 2,
      },
      {
          .nums{2, 3, 3, 10},
          .threshold = 18,
          .expected = 2,
      },
      {
          .nums{3, 2, 5, 4},
          .threshold = 5,
          .expected = 3,
      },
      {
          .nums{1, 2},
          .threshold = 2,
          .expected = 1,
      },
      {
          .nums{2, 3, 4, 5},
          .threshold = 4,
          .expected = 3,
      },
      {
          .nums{5},
          .threshold = 1,
          .expected = 0,
      },
  };

  for (const auto &[nums, threshold, expected] : test_cases) {
    const auto actual = Solution::longestAlternatingSubarray(nums, threshold);
    REQUIRE(expected == actual);
  }
}

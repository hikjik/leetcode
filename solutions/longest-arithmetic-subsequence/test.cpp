#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 6, 9, 12},
          .expected = 4,
      },
      {
          .nums{9, 4, 7, 2, 10},
          .expected = 3,
      },
      {
          .nums{20, 1, 15, 3, 10, 5, 8},
          .expected = 4,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::longestArithSeqLength(nums);
    REQUIRE(expected == actual);
  }
}

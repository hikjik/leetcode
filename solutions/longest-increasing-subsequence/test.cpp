#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{10, 9, 2, 5, 3, 7, 101, 18},
          .expected = 4,
      },
      {
          .nums{0, 1, 0, 3, 2, 3},
          .expected = 4,
      },
      {
          .nums{7, 7, 7, 7, 7, 7, 7},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::lengthOfLIS(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 0, 1},
          .expected = 3,
      },
      {
          .nums{0, 1, 1, 1, 0, 1, 1, 0, 1},
          .expected = 5,
      },
      {
          .nums{1, 1, 1},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::longestSubarray(nums);
    REQUIRE(expected == actual);
  }
}

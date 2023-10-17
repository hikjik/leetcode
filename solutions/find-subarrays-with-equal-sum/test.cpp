#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 2, 4},
          .expected = true,
      },
      {
          .nums{1, 2, 3, 4, 5},
          .expected = false,
      },
      {
          .nums{0, 0, 0},
          .expected = true,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findSubarrays(nums);
    REQUIRE(expected == actual);
  }
}

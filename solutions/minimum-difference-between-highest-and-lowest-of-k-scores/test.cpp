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
          .nums{90},
          .k = 1,
          .expected = 0,
      },
      {
          .nums{9, 4, 1, 7},
          .k = 2,
          .expected = 2,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::minimumDifference(nums, k);
    REQUIRE(expected == actual);
  }
}

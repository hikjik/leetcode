#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 1, 2, 2},
          .expected = 4,
      },
      {
          .nums{5, 5, 5, 5},
          .expected = 10,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::countCompleteSubarrays(nums);
    REQUIRE(expected == actual);
  }
}

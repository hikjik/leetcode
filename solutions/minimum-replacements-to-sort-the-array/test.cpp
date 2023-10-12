#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 9, 3},
          .expected = 2,
      },
      {
          .nums{1, 2, 3, 4, 5},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimumReplacement(nums);
    REQUIRE(expected == actual);
  }
}

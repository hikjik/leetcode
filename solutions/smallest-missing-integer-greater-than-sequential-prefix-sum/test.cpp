#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 2, 5},
          .expected = 6,
      },
      {
          .nums{3, 4, 5, 1, 12, 14, 13},
          .expected = 15,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::missingInteger(nums);
    REQUIRE(expected == actual);
  }
}

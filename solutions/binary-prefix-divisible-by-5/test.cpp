#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<bool> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 1},
          .expected{true, false, false},
      },
      {
          .nums{1, 1, 1},
          .expected{false, false, false},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::prefixesDivBy5(nums);
    REQUIRE(expected == actual);
  }
}

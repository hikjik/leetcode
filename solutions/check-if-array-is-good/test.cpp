#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 1, 3},
          .expected = false,
      },
      {
          .nums{1, 3, 3, 2},
          .expected = true,
      },
      {
          .nums{1, 1},
          .expected = true,
      },
      {
          .nums{3, 4, 4, 1, 2, 1},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::isGood(nums);
    REQUIRE(expected == actual);
  }
}

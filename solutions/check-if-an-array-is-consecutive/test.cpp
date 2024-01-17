#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 4, 2},
          .expected = true,
      },
      {
          .nums{1, 3},
          .expected = false,
      },
      {
          .nums{3, 5, 4},
          .expected = true,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::isConsecutive(nums);
    REQUIRE(expected == actual);
  }
}

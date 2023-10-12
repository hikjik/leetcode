#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 4, 5, 1, 2},
          .expected = true,
      },
      {
          .nums{2, 1, 3, 4},
          .expected = false,
      },
      {
          .nums{1, 2, 3},
          .expected = true,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::check(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 5, 2},
          .expected = false,
      },
      {
          .nums{1, 5, 233, 7},
          .expected = true,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::predictTheWinner(nums);
    REQUIRE(expected == actual);
  }
}

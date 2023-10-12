#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 2, 3},
          .expected = 3,
      },
      {
          .nums{2, 2, 1, 1, 1, 2, 2},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::majorityElement(nums);
    REQUIRE(expected == actual);
  }
}

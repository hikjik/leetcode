#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 7, 1, 6},
          .expected = 5,
      },
      {
          .nums{10, 1},
          .expected = 10,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimizeArrayValue(nums);
    REQUIRE(expected == actual);
  }
}

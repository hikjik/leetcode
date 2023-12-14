#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 2, 4},
          .expected = 1,
      },
      {
          .nums{100, 1, 10},
          .expected = 9,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findValueOfPartition(nums);
    REQUIRE(expected == actual);
  }
}

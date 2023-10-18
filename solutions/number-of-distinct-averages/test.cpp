#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 1, 4, 0, 3, 5},
          .expected = 2,
      },
      {
          .nums{1, 100},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::distinctAverages(nums);
    REQUIRE(expected == actual);
  }
}

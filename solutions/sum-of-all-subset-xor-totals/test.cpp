#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3},
          .expected = 6,
      },
      {
          .nums{5, 1, 6},
          .expected = 28,
      },
      {
          .nums{3, 4, 5, 6, 7, 8},
          .expected = 480,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::subsetXORSum(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 1, 2, 3},
          .expected{2, 3, 4, 1},
      },
      {
          .nums{2, 1},
          .expected{2, 1},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::sortEvenOdd(nums);
    REQUIRE(expected == actual);
  }
}

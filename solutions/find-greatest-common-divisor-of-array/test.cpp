#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 5, 6, 9, 10},
          .expected = 2,
      },
      {
          .nums{7, 5, 6, 8, 3},
          .expected = 1,
      },
      {
          .nums{3, 3},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findGCD(nums);
    REQUIRE(expected == actual);
  }
}

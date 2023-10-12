#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .expected = 1,
      },
      {
          .nums{4, 1, 5, 20, 3},
          .expected = 3,
      },
      {
          .nums{2, 10, 8},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimumDeviation(nums);
    REQUIRE(expected == actual);
  }
}

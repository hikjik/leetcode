#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 3},
          .expected = 3,
      },
      {
          .nums{2, 1, 2, 5, 3, 2},
          .expected = 2,
      },
      {
          .nums{5, 1, 5, 2, 5, 3, 5, 4},
          .expected = 5,
      },
      {
          .nums{5, 1, 2, 5, 3, 4, 5, 5},
          .expected = 5,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::repeatedNTimes(nums);
    REQUIRE(expected == actual);
  }
}

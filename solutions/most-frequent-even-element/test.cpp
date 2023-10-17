#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 2, 2, 4, 4, 1},
          .expected = 2,
      },
      {
          .nums{4, 4, 4, 9, 2, 4},
          .expected = 4,
      },
      {
          .nums{29, 47, 21, 41, 13, 37, 25, 7},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::mostFrequentEven(nums);
    REQUIRE(expected == actual);
  }
}

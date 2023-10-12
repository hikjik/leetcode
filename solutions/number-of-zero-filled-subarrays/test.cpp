#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 0, 0, 2, 0, 0, 4},
          .expected = 6,
      },
      {
          .nums{0, 0, 0, 2, 0, 0},
          .expected = 9,
      },
      {
          .nums{2, 10, 2019},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::zeroFilledSubarray(nums);
    REQUIRE(expected == actual);
  }
}

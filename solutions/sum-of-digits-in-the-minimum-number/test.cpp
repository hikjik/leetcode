#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{34, 23, 1, 24, 75, 33, 54, 8},
          .expected = 0,
      },
      {
          .nums{99, 77, 33, 66, 55},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::sumOfDigits(nums);
    REQUIRE(expected == actual);
  }
}

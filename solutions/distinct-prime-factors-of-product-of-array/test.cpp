#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 4, 3, 7, 10, 6},
          .expected = 4,
      },
      {
          .nums{2, 4, 8, 16},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::distinctPrimeFactors(nums);
    REQUIRE(expected == actual);
  }
}

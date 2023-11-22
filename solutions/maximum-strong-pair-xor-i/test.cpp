#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5},
          .expected = 7,
      },
      {
          .nums{10, 100},
          .expected = 0,
      },
      {
          .nums{5, 6, 25, 30},
          .expected = 7,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maximumStrongPairXor(nums);
    REQUIRE(expected == actual);
  }
}

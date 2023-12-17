#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5},
          .expected = 6,
      },
      {
          .nums{10, 12, 13, 14, 15},
          .expected = 11,
      },
      {
          .nums{22, 33, 22, 33, 22},
          .expected = 22,
      },
      {
          .nums{1'000'000'000 - 2, 1'000'000'000},
          .expected = 2,
      },
      {
          .nums{1'000'000'000},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minimumCost(nums);
    REQUIRE(expected == actual);
  }
}

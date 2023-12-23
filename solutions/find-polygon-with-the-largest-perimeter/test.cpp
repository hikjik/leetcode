#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 5, 5},
          .expected = 15,
      },
      {
          .nums{1, 12, 1, 2, 5, 50, 3},
          .expected = 12,
      },
      {
          .nums{5, 5, 50},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::largestPerimeter(nums);
    REQUIRE(expected == actual);
  }
}

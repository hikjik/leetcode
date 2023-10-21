#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 4, 5, 2},
          .expected = 12,
      },
      {
          .nums{1, 5, 4, 5},
          .expected = 16,
      },
      {
          .nums{3, 7},
          .expected = 12,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxProduct(nums);
    REQUIRE(expected == actual);
  }
}

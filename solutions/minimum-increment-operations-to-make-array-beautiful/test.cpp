#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 0, 0, 2},
          .k = 4,
          .expected = 3,
      },
      {
          .nums{0, 1, 3, 3},
          .k = 5,
          .expected = 2,
      },
      {
          .nums{1, 1, 2},
          .k = 1,
          .expected = 0,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::minIncrementOperations(nums, k);
    REQUIRE(expected == actual);
  }
}

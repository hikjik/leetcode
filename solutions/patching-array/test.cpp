#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3},
          .n = 6,
          .expected = 1,
      },
      {
          .nums{1, 5, 10},
          .n = 20,
          .expected = 2,
      },
      {
          .nums{1, 2, 2},
          .n = 5,
          .expected = 0,
      },
      {
          .nums{1, 64, 346},
          .n = 2147483647,
          .expected = 29,
      },
  };

  for (const auto &[nums, n, expected] : test_cases) {
    const auto actual = Solution::minPatches(nums, n);
    REQUIRE(expected == actual);
  }
}

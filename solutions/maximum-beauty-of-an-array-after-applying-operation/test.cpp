#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 6, 1, 2},
          .k = 2,
          .expected = 3,
      },
      {
          .nums{1, 1, 1, 1},
          .k = 10,
          .expected = 4,
      },
      {
          .nums{1},
          .k = 1,
          .expected = 1,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::maximumBeauty(nums, k);
    REQUIRE(expected == actual);
  }
}

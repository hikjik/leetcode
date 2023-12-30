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
          .nums{1, 1, 2, 1, 1},
          .k = 3,
          .expected = 2,
      },
      {
          .nums{2, 4, 6},
          .k = 1,
          .expected = 0,
      },
      {
          .nums{2, 2, 2, 1, 2, 2, 1, 2, 2, 2},
          .k = 2,
          .expected = 16,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::numberOfSubarrays(nums, k);
    REQUIRE(expected == actual);
  }
}

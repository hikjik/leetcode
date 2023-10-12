#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int minK;
    int maxK;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 5, 2, 7, 5},
          .minK = 1,
          .maxK = 5,
          .expected = 2,
      },
      {
          .nums{1, 1, 1, 1},
          .minK = 1,
          .maxK = 1,
          .expected = 10,
      },
  };

  for (const auto &[nums, minK, maxK, expected] : test_cases) {
    const auto actual = Solution::countSubarrays(nums, minK, maxK);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int key;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 4, 9, 1, 3, 9, 5},
          .key = 9,
          .k = 1,
          .expected{1, 2, 3, 4, 5, 6},
      },
      {
          .nums{2, 2, 2, 2, 2},
          .key = 2,
          .k = 2,
          .expected{0, 1, 2, 3, 4},
      },
  };

  for (const auto &[nums, key, k, expected] : test_cases) {
    const auto actual = Solution::findKDistantIndices(nums, key, k);
    REQUIRE(expected == actual);
  }
}

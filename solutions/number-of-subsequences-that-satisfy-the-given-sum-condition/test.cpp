#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 5, 6, 7},
          .target = 9,
          .expected = 4,
      },
      {
          .nums{3, 3, 6, 8},
          .target = 10,
          .expected = 6,
      },
      {
          .nums{2, 3, 3, 4, 6, 7},
          .target = 12,
          .expected = 61,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::numSubseq(nums, target);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int n;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 5, 1, 3, 4, 7},
          .n = 3,
          .expected{2, 3, 5, 4, 1, 7},
      },
      {
          .nums{1, 2, 3, 4, 4, 3, 2, 1},
          .n = 4,
          .expected{1, 4, 2, 3, 3, 2, 4, 1},
      },
      {
          .nums{1, 1, 2, 2},
          .n = 2,
          .expected{1, 2, 1, 2},
      },
  };

  for (const auto &[nums, n, expected] : test_cases) {
    const auto actual = Solution::shuffle(nums, n);
    REQUIRE(expected == actual);
  }
}

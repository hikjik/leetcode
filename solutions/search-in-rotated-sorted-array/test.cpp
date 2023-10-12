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
          .nums{4, 5, 6, 7, 0, 1, 2},
          .target = 0,
          .expected = 4,
      },
      {
          .nums{4, 5, 6, 7, 0, 1, 2},
          .target = 3,
          .expected = -1,
      },
      {
          .nums{1},
          .target = 0,
          .expected = -1,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::search(nums, target);
    REQUIRE(expected == actual);
  }
}

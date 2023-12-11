#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> target;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{8, 12, 6},
          .target{2, 14, 10},
          .expected = 2,
      },
      {
          .nums{1, 2, 5},
          .target{4, 1, 3},
          .expected = 1,
      },
      {
          .nums{1, 1, 1, 1, 1},
          .target{1, 1, 1, 1, 1},
          .expected = 0,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::makeSimilar(nums, target);
    REQUIRE(expected == actual);
  }
}

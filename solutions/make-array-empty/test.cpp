#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 4, -1},
          .expected = 5,
      },
      {
          .nums{1, 2, 4, 3},
          .expected = 5,
      },
      {
          .nums{1, 2, 3},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::countOperationsToEmptyArray(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 1, 3},
          .expected = 3,
      },
      {
          .nums{1, 1, 1},
          .expected = 0,
      },
      {
          .nums{1, 1, 2, 2, 3},
          .expected = 4,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::reductionOperations(nums);
    REQUIRE(expected == actual);
  }
}

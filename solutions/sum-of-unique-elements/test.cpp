#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 2},
          .expected = 4,
      },
      {
          .nums{1, 1, 1, 1, 1},
          .expected = 0,
      },
      {
          .nums{1, 2, 3, 4, 5},
          .expected = 15,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::sumOfUnique(nums);
    REQUIRE(expected == actual);
  }
}

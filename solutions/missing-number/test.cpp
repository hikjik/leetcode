#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 0, 1},
          .expected = 2,
      },
      {
          .nums{0, 1},
          .expected = 2,
      },
      {
          .nums{9, 6, 4, 2, 3, 5, 7, 0, 1},
          .expected = 8,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::missingNumber(nums);
    REQUIRE(expected == actual);
  }
}

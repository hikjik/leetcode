#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 7, 4, 9, 2, 5},
          .expected = 6,
      },
      {
          .nums{1, 17, 5, 10, 13, 15, 10, 5, 16, 8},
          .expected = 7,
      },
      {
          .nums{1, 2, 3, 4, 5, 6, 7, 8, 9},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::wiggleMaxLength(nums);
    REQUIRE(expected == actual);
  }
}

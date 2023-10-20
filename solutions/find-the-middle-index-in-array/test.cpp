#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, -1, 8, 4},
          .expected = 3,
      },
      {
          .nums{1, -1, 4},
          .expected = 2,
      },
      {
          .nums{2, 5},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findMiddleIndex(nums);
    REQUIRE(expected == actual);
  }
}

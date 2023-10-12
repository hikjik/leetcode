#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 4, 5, 1, 2},
          .expected = 1,
      },
      {
          .nums{4, 5, 6, 7, 0, 1, 2},
          .expected = 0,
      },
      {
          .nums{11, 13, 15, 17},
          .expected = 11,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findMin(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .expected = 8,
      },
      {
          .nums{1, 1, 1, 1},
          .expected = 1,
      },
      {
          .nums{1, 2, 1, 3},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::numberOfGoodPartitions(nums);
    REQUIRE(expected == actual);
  }
}

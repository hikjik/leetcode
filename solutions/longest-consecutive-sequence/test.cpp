#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{100, 4, 200, 1, 3, 2},
          .expected = 4,
      },
      {
          .nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1},
          .expected = 9,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::longestConsecutive(nums);
    REQUIRE(expected == actual);
  }
}

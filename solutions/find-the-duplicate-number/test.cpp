#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 4, 2, 2},
          .expected = 2,
      },
      {
          .nums{3, 1, 3, 4, 2},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findDuplicate(nums);
    REQUIRE(expected == actual);
  }
}

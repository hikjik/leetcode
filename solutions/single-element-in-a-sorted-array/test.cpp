#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 2, 3, 3, 4, 4, 8, 8},
          .expected = 2,
      },
      {
          .nums{3, 3, 7, 7, 10, 11, 11},
          .expected = 10,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::singleNonDuplicate(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{13, 25, 83, 77},
          .expected{1, 3, 2, 5, 8, 3, 7, 7},
      },
      {
          .nums{7, 1, 3, 9},
          .expected{7, 1, 3, 9},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::separateDigits(nums);
    REQUIRE(expected == actual);
  }
}

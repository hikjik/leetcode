#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 2, 1, 5, 3, 4},
          .expected{0, 1, 2, 4, 5, 3},
      },
      {
          .nums{5, 0, 1, 2, 3, 4},
          .expected{4, 5, 0, 1, 2, 3},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::buildArray(nums);
    REQUIRE(expected == actual);
  }
}

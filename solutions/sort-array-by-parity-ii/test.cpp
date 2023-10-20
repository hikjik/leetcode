#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 2, 5, 7},
          .expected{4, 5, 2, 7},
      },
      {
          .nums{2, 3},
          .expected{2, 3},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::sortArrayByParityII(nums);
    REQUIRE(expected == actual);
  }
}

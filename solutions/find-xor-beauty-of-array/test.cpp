#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 4},
          .expected = 5,
      },
      {
          .nums{15, 45, 20, 2, 34, 35, 5, 44, 32, 30},
          .expected = 34,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::xorBeauty(nums);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 2, 4, 6},
          .expected = 7,
      },
      {
          .nums{1, 2, 3, 9, 2},
          .expected = 11,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maximumXOR(nums);
    REQUIRE(expected == actual);
  }
}

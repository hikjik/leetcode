#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 2, 1, 4, 5},
          .expected = 2,
      },
      {
          .nums{3, 2, 6, 1, 4},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxOperations(nums);
    REQUIRE(expected == actual);
  }
}

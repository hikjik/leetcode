#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .k = 5,
          .expected = 2,
      },
      {
          .nums{3, 1, 3, 4, 3},
          .k = 6,
          .expected = 1,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::maxOperations(nums, k);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 4, 6},
          .expected = 8,
      },
      {
          .nums{1, 2, 4, 5, 10},
          .expected = 16,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::tupleSameProduct(nums);
    REQUIRE(expected == actual);
  }
}

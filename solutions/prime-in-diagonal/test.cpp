#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{{1, 2, 3}, {5, 6, 7}, {9, 10, 11}},
          .expected = 11,
      },
      {
          .nums{{1, 2, 3}, {5, 17, 7}, {9, 11, 10}},
          .expected = 17,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::diagonalPrime(nums);
    REQUIRE(expected == actual);
  }
}

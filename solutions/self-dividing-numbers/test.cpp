#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int left;
    int right;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .left = 1,
          .right = 22,
          .expected{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22},
      },
      {
          .left = 47,
          .right = 85,
          .expected{48, 55, 66, 77},
      },
  };

  for (const auto &[left, right, expected] : test_cases) {
    const auto actual = Solution::selfDividingNumbers(left, right);
    REQUIRE(expected == actual);
  }
}

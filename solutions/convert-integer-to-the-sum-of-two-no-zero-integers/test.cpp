#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected{1, 1},
      },
      {
          .n = 11,
          .expected{2, 9},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::getNoZeroIntegers(n);
    REQUIRE(expected == actual);
  }
}

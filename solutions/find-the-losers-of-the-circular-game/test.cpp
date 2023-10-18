#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 5,
          .k = 2,
          .expected{4, 5},
      },
      {
          .n = 4,
          .k = 4,
          .expected{2, 3, 4},
      },
  };

  for (const auto &[n, k, expected] : test_cases) {
    const auto actual = Solution::circularGameLosers(n, k);
    REQUIRE(expected == actual);
  }
}

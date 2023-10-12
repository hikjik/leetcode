#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> cuts;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 7,
          .cuts{1, 3, 4, 5},
          .expected = 16,
      },
      {
          .n = 9,
          .cuts{5, 6, 1, 4, 2},
          .expected = 22,
      },
  };

  for (const auto &[n, cuts, expected] : test_cases) {
    const auto actual = Solution().minCost(n, cuts);
    REQUIRE(expected == actual);
  }
}

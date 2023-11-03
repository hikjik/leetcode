#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .expected{{".Q..", "...Q", "Q...", "..Q."},
                    {"..Q.", "Q...", "...Q", ".Q.."}},
      },
      {
          .n = 1,
          .expected{{"Q"}},
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution().solveNQueens(n);
    REQUIRE(expected == actual);
  }
}

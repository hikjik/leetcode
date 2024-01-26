#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int m;
    int n;
    int maxMove;
    int startRow;
    int startColumn;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .m = 2,
          .n = 2,
          .maxMove = 2,
          .startRow = 0,
          .startColumn = 0,
          .expected = 6,
      },
      {
          .m = 1,
          .n = 3,
          .maxMove = 3,
          .startRow = 0,
          .startColumn = 1,
          .expected = 12,
      },
  };

  SECTION("Memoization") {
    for (const auto &[m, n, maxMove, startRow, startColumn, expected] :
         test_cases) {
      const auto actual =
          memo::Solution::findPaths(m, n, maxMove, startRow, startColumn);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[m, n, maxMove, startRow, startColumn, expected] :
         test_cases) {
      const auto actual =
          dp::Solution::findPaths(m, n, maxMove, startRow, startColumn);
      REQUIRE(expected == actual);
    }
  }
}

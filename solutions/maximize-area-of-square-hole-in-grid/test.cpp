#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int m;
    std::vector<int> hBars;
    std::vector<int> vBars;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .m = 1,
          .hBars{2, 3},
          .vBars{2},
          .expected = 4,
      },
      {
          .n = 1,
          .m = 1,
          .hBars{2},
          .vBars{2},
          .expected = 4,
      },
      {
          .n = 2,
          .m = 3,
          .hBars{2, 3},
          .vBars{2, 3, 4},
          .expected = 9,
      },
  };

  for (const auto &[n, m, hBars, vBars, expected] : test_cases) {
    const auto actual = Solution::maximizeSquareHoleArea(n, m, hBars, vBars);
    REQUIRE(expected == actual);
  }
}

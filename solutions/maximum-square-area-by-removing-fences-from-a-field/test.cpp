#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int m;
    int n;
    std::vector<int> hFences;
    std::vector<int> vFences;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .m = 4,
          .n = 3,
          .hFences{2, 3},
          .vFences{2},
          .expected = 4,
      },
      {
          .m = 6,
          .n = 7,
          .hFences{2},
          .vFences{4},
          .expected = -1,
      },
  };

  for (const auto &[m, n, hFences, vFences, expected] : test_cases) {
    const auto actual = Solution::maximizeSquareArea(m, n, hFences, vFences);
    REQUIRE(expected == actual);
  }
}

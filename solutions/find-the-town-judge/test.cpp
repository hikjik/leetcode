#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> trust;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .trust{{1, 2}},
          .expected = 2,
      },
      {
          .n = 3,
          .trust{{1, 3}, {2, 3}},
          .expected = 3,
      },
      {
          .n = 3,
          .trust{{1, 3}, {2, 3}, {3, 1}},
          .expected = -1,
      },
  };

  for (const auto &[n, trust, expected] : test_cases) {
    const auto actual = Solution::findJudge(n, trust);
    REQUIRE(expected == actual);
  }
}

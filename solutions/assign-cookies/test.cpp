#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> g;
    std::vector<int> s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .g{1, 2, 3},
          .s{1, 1},
          .expected = 1,
      },
      {
          .g{1, 2},
          .s{1, 2, 3},
          .expected = 2,
      },
  };

  for (const auto &[g, s, expected] : test_cases) {
    const auto actual = Solution::findContentChildren(g, s);
    REQUIRE(expected == actual);
  }
}

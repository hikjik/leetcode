#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"acca", "bbbb", "caca"},
          .target = "aba",
          .expected = 6,
      },
      {
          .words{"abba", "baab"},
          .target = "bab",
          .expected = 4,
      },
  };

  for (const auto &[words, target, expected] : test_cases) {
    const auto actual = Solution::numWays(words, target);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"aba", "aabb", "abcd", "bac", "aabc"},
          .expected = 2,
      },
      {
          .words{"aabb", "ab", "ba"},
          .expected = 3,
      },
      {
          .words{"nba", "cba", "dba"},
          .expected = 0,
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::similarPairs(words);
    REQUIRE(expected == actual);
  }
}

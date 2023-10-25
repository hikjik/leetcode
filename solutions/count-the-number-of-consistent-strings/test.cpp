#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string allowed;
    std::vector<std::string> words;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .allowed = "ab",
          .words{"ad", "bd", "aaab", "baa", "badab"},
          .expected = 2,
      },
      {
          .allowed = "abc",
          .words{"a", "b", "c", "ab", "ac", "bc", "abc"},
          .expected = 7,
      },
      {
          .allowed = "cad",
          .words{"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"},
          .expected = 4,
      },
  };

  for (const auto &[allowed, words, expected] : test_cases) {
    const auto actual = Solution::countConsistentStrings(allowed, words);
    REQUIRE(expected == actual);
  }
}

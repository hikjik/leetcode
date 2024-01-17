#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string text;
    std::vector<std::string> words;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .text = "thestoryofleetcodeandme",
          .words{"story", "fleet", "leetcode"},
          .expected{{3, 7}, {9, 13}, {10, 17}},
      },
      {
          .text = "ababa",
          .words{"aba", "ab"},
          .expected{{0, 1}, {0, 2}, {2, 3}, {2, 4}},
      },
  };

  SECTION("String Match Set") {
    for (const auto &[text, words, expected] : test_cases) {
      const auto actual = match::Solution::indexPairs(text, words);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Hash Set") {
    for (const auto &[text, words, expected] : test_cases) {
      const auto actual = hs::Solution::indexPairs(text, words);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Trie") {
    for (const auto &[text, words, expected] : test_cases) {
      const auto actual = trie::Solution::indexPairs(text, words);
      REQUIRE(expected == actual);
    }
  }
}

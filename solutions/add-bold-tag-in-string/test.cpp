#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> words;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcxyz123",
          .words{"abc", "123"},
          .expected = "<b>abc</b>xyz<b>123</b>",
      },
      {
          .s = "aaabbb",
          .words{"aa", "b"},
          .expected = "<b>aaabbb</b>",
      },
  };

  SECTION("Bold Array") {
    for (const auto &[s, words, expected] : test_cases) {
      const auto actual = bold::Solution::addBoldTag(s, words);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Trie") {
    for (const auto &[s, words, expected] : test_cases) {
      const auto actual = trie::Solution::addBoldTag(s, words);
      REQUIRE(expected == actual);
    }
  }
}

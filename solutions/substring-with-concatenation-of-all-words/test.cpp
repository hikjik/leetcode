#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> words;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "barfoothefoobarman",
          .words{"foo", "bar"},
          .expected{0, 9},
      },
      {
          .s = "wordgoodgoodgoodbestword",
          .words{"word", "good", "best", "word"},
          .expected{},
      },
      {
          .s = "barfoofoobarthefoobarman",
          .words{"bar", "foo", "the"},
          .expected{6, 9, 12},
      },
  };

  for (const auto &[s, words, expected] : test_cases) {
    const auto actual = Solution::findSubstring(s, words);
    REQUIRE(expected == actual);
  }
}

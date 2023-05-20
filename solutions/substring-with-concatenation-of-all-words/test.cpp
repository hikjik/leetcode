#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string s = "barfoothefoobarman";
    std::vector<std::string> words{"foo", "bar"};
    std::vector<int> expected{0, 9};
    REQUIRE(expected == Solution::findSubstring(s, words));
  }
  {
    std::string s = "wordgoodgoodgoodbestword";
    std::vector<std::string> words{"word", "good", "best", "word"};
    std::vector<int> expected;
    REQUIRE(expected == Solution::findSubstring(s, words));
  }
  {
    std::string s = "barfoofoobarthefoobarman";
    std::vector<std::string> words{"bar", "foo", "the"};
    std::vector<int> expected{6, 9, 12};
    REQUIRE(expected == Solution::findSubstring(s, words));
  }
}

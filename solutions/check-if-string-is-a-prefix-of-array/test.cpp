#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> words;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "iloveleetcode",
          .words{"i", "love", "leetcode", "apples"},
          .expected = true,
      },
      {
          .s = "iloveleetcode",
          .words{"apples", "i", "love", "leetcode"},
          .expected = false,
      },
  };

  for (const auto &[s, words, expected] : test_cases) {
    const auto actual = Solution::isPrefixString(s, words);
    REQUIRE(expected == actual);
  }
}

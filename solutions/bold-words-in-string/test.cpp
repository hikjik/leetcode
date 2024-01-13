#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"ab", "bc"},
          .s = "aabcd",
          .expected = "a<b>abc</b>d",
      },
      {
          .words{"ab", "cb"},
          .s = "aabcd",
          .expected = "a<b>ab</b>cd",
      },
  };

  for (const auto &[words, s, expected] : test_cases) {
    const auto actual = Solution::boldWords(words, s);
    REQUIRE(expected == actual);
  }
}

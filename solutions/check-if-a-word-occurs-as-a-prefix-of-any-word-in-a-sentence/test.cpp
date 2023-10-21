#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string sentence;
    std::string searchWord;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sentence = "i love eating burger",
          .searchWord = "burg",
          .expected = 4,
      },
      {
          .sentence = "this problem is an easy problem",
          .searchWord = "pro",
          .expected = 2,
      },
      {
          .sentence = "i am tired",
          .searchWord = "you",
          .expected = -1,
      },
  };

  for (const auto &[sentence, searchWord, expected] : test_cases) {
    const auto actual = Solution::isPrefixOfWord(sentence, searchWord);
    REQUIRE(expected == actual);
  }
}

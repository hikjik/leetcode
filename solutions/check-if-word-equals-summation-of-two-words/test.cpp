#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string firstWord;
    std::string secondWord;
    std::string targetWord;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .firstWord = "acb",
          .secondWord = "cba",
          .targetWord = "cdb",
          .expected = true,
      },
      {
          .firstWord = "aaa",
          .secondWord = "a",
          .targetWord = "aab",
          .expected = false,
      },
      {
          .firstWord = "aaa",
          .secondWord = "a",
          .targetWord = "aaaa",
          .expected = true,
      },
  };

  for (const auto &[firstWord, secondWord, targetWord, expected] : test_cases) {
    const auto actual = Solution::isSumEqual(firstWord, secondWord, targetWord);
    REQUIRE(expected == actual);
  }
}

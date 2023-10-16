#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string secret;
    std::vector<std::string> words;
    int allowedGuesses;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .secret = "acckzz",
          .words{"acckzz", "ccbazz", "eiowzz", "abcczz"},
          .allowedGuesses = 10,
          .expected = "You guessed the secret word correctly.",
      },
      {
          .secret = "hamada",
          .words{"hamada", "khaled"},
          .allowedGuesses = 10,
          .expected = "You guessed the secret word correctly.",
      },
  };

  for (const auto &[secret, words, allowedGuesses, expected] : test_cases) {
    Master master(words, secret, allowedGuesses);
    Solution::findSecretWord(words, master);
    REQUIRE(expected == master.message());
  }
}

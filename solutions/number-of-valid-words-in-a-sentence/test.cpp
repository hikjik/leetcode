#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string sentence;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sentence = "cat and  dog",
          .expected = 3,
      },
      {
          .sentence = "!this  1-s b8d!",
          .expected = 0,
      },
      {
          .sentence = "alice and  bob are playing stone-game10",
          .expected = 5,
      },
      {
          .sentence = "cat and  dog a",
          .expected = 4,
      },
      {
          .sentence = "!",
          .expected = 1,
      },
  };

  for (const auto &[sentence, expected] : test_cases) {
    const auto actual = Solution::countValidWords(sentence);
    REQUIRE(expected == actual);
  }
}

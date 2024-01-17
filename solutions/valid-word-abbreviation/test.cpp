#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    std::string abbr;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "apple",
          .abbr = "a2e",
          .expected = false,
      },
      {
          .word = "internationalization",
          .abbr = "i12iz4n",
          .expected = true,
      },
      {
          .word = "substitution",
          .abbr = "s0ubstitution",
          .expected = false,
      },
      {
          .word = "substitution",
          .abbr = "s010n",
          .expected = false,
      },
  };

  for (const auto &[word, abbr, expected] : test_cases) {
    const auto actual = Solution::validWordAbbreviation(word, abbr);
    REQUIRE(expected == actual);
  }
}

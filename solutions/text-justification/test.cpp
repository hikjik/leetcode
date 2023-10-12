#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    int maxWidth;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"This", "is", "an", "example", "of", "text", "justification."},
          .maxWidth = 16,
          .expected{"This    is    an", "example  of text", "justification.  "},
      },
      {
          .words{"What", "must", "be", "acknowledgment", "shall", "be"},
          .maxWidth = 16,
          .expected{"What   must   be", "acknowledgment  ", "shall be        "},
      },
      {
          .words{"Science", "is", "what", "we", "understand", "well", "enough",
                 "to", "explain", "to", "a", "computer.", "Art", "is",
                 "everything", "else", "we", "do"},
          .maxWidth = 20,
          .expected{"Science  is  what we", "understand      well",
                    "enough to explain to", "a  computer.  Art is",
                    "everything  else  we", "do                  "},
      },
  };

  for (const auto &[words, maxWidth, expected] : test_cases) {
    const auto actual = Solution::fullJustify(words, maxWidth);
    REQUIRE(expected == actual);
  }
}

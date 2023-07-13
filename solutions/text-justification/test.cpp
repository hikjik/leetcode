#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int max_width = 16;
    std::vector<std::string> words{
        "This", "is", "an", "example", "of", "text", "justification."};
    std::vector<std::string> expected{"This    is    an", "example  of text",
                                      "justification.  "};
    REQUIRE(expected == Solution::fullJustify(words, max_width));
  }
  {
    int max_width = 16;
    std::vector<std::string> words{"What",           "must",  "be",
                                   "acknowledgment", "shall", "be"};
    std::vector<std::string> expected{"What   must   be", "acknowledgment  ",
                                      "shall be        "};
    REQUIRE(expected == Solution::fullJustify(words, max_width));
  }
  {
    int max_width = 20;
    std::vector<std::string> words{
        "Science", "is", "what",       "we",   "understand", "well",
        "enough",  "to", "explain",    "to",   "a",          "computer.",
        "Art",     "is", "everything", "else", "we",         "do"};
    std::vector<std::string> expected{
        "Science  is  what we", "understand      well", "enough to explain to",
        "a  computer.  Art is", "everything  else  we", "do                  "};
    REQUIRE(expected == Solution::fullJustify(words, max_width));
  }
}

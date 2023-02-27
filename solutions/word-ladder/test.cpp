#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string begin_word = "hit";
    std::string end_word = "cog";
    std::vector<std::string> word_list{"hot", "dot", "dog",
                                       "lot", "log", "cog"};
    REQUIRE(5 == Solution::ladderLength(begin_word, end_word, word_list));
  }
  {
    std::string begin_word = "hit";
    std::string end_word = "cog";
    std::vector<std::string> word_list{"hot", "dot", "dog", "lot", "log"};
    REQUIRE(0 == Solution::ladderLength(begin_word, end_word, word_list));
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto word_dictionary = WordDictionary();

  word_dictionary.addWord("bad");
  word_dictionary.addWord("dad");
  word_dictionary.addWord("mad");
  REQUIRE(false == word_dictionary.search("pad"));
  REQUIRE(true == word_dictionary.search("bad"));
  REQUIRE(true == word_dictionary.search(".ad"));
  REQUIRE(true == word_dictionary.search("b.."));
}

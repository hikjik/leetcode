#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> words{"hello", "leetcode"};
    std::string order = "hlabcdefgijkmnopqrstuvwxyz";
    REQUIRE(Solution::isAlienSorted(words, order));
  }
  {
    std::vector<std::string> words{"word", "world", "row"};
    std::string order = "worldabcefghijkmnpqstuvxyz";
    REQUIRE_FALSE(Solution::isAlienSorted(words, order));
  }
  {
    std::vector<std::string> words{"apple", "app"};
    std::string order = "abcdefghijklmnopqrstuvwxyz";
    REQUIRE_FALSE(Solution::isAlienSorted(words, order));
  }
}

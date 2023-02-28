#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string str = "leetcode";
    std::vector<std::string> words{"leet", "code"};
    REQUIRE(Solution::wordBreak(str, words));
  }
  {
    std::string str = "applepenapple";
    std::vector<std::string> words{"apple", "pen"};
    REQUIRE(Solution::wordBreak(str, words));
  }
  {
    std::string str = "catsandog";
    std::vector<std::string> words{"cats", "dog", "sand", "and", "cat"};
    REQUIRE_FALSE(Solution::wordBreak(str, words));
  }
}

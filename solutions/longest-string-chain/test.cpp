#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> words{"a", "b", "ba", "bca", "bda", "bdca"};
    REQUIRE(4 == Solution::longestStrChain(words));
  }
  {
    std::vector<std::string> words{"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    REQUIRE(5 == Solution::longestStrChain(words));
  }
  {
    std::vector<std::string> words{"abcd", "dbqca"};
    REQUIRE(1 == Solution::longestStrChain(words));
  }
}

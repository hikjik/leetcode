#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string s = "aab";
    std::vector<std::vector<std::string>> expected{{"a", "a", "b"},
                                                   {"aa", "b"}};
    REQUIRE(expected == Solution::partition(s));
  }
  {
    std::string s = "a";
    std::vector<std::vector<std::string>> expected{{"a"}};
    REQUIRE(expected == Solution::partition(s));
  }
}

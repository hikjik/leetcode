#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> expected{
        {"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
    REQUIRE(expected == Solution::groupAnagrams(strs));
  }
  {
    std::vector<std::string> strs{""};
    std::vector<std::vector<std::string>> expected{{""}};
    REQUIRE(expected == Solution::groupAnagrams(strs));
  }
  {
    std::vector<std::string> strs{"a"};
    std::vector<std::vector<std::string>> expected{{"a"}};
    REQUIRE(expected == Solution::groupAnagrams(strs));
  }
}

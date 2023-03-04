#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> strs{"flower", "flow", "flight"};
    std::string prefix = "fl";
    REQUIRE(prefix == Solution::longestCommonPrefix(strs));
  }
  {
    std::vector<std::string> strs{"dog", "racecar", "car"};
    std::string prefix = "";
    REQUIRE(prefix == Solution::longestCommonPrefix(strs));
  }
  {
    std::vector<std::string> strs{"flower", "flower", "flower", "flower"};
    std::string prefix = "flower";
    REQUIRE(prefix == Solution::longestCommonPrefix(strs));
  }
}

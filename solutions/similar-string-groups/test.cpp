#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> strs{"tars", "rats", "arts", "star"};
    REQUIRE(2 == Solution::numSimilarGroups(strs));
  }
  {
    std::vector<std::string> strs{"omv", "ovm"};
    REQUIRE(1 == Solution::numSimilarGroups(strs));
  }
}

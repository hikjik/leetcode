#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string s = "ababcbacadefegdehijhklij";
    std::vector<int> expected{9, 7, 8};
    REQUIRE(expected == Solution::partitionLabels(s));
  }
  {
    std::string s = "eccbbbbdec";
    std::vector<int> expected{10};
    REQUIRE(expected == Solution::partitionLabels(s));
  }
}

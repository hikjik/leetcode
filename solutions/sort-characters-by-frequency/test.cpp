#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("eert" == Solution::frequencySort("tree"));
  REQUIRE("aaaccc" == Solution::frequencySort("cccaaa"));
  REQUIRE("bbAa" == Solution::frequencySort("Aabb"));
  REQUIRE("eeeee" == Solution::frequencySort("eeeee"));
}

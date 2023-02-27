#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> expected{0, 6};
    REQUIRE(expected == Solution::findAnagrams("cbaebabacd", "abc"));
  }
  {
    std::vector<int> expected{0, 1, 2};
    REQUIRE(expected == Solution::findAnagrams("abab", "ab"));
  }
}

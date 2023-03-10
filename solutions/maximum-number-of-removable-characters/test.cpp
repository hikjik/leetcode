#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string s = "abcacb", p = "ab";
    std::vector<int> removable{3, 1, 0};
    REQUIRE(2 == Solution::maximumRemovals(s, p, removable));
  }
  {
    std::string s = "abcbddddd", p = "abcd";
    std::vector<int> removable{3, 2, 1, 4, 5, 6};
    REQUIRE(1 == Solution::maximumRemovals(s, p, removable));
  }
  {
    std::string s = "abcab", p = "abc";
    std::vector<int> removable{0, 1, 2, 3, 4};
    REQUIRE(0 == Solution::maximumRemovals(s, p, removable));
  }
}

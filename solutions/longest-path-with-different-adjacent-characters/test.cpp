#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> parent{-1, 0, 0, 1, 1, 2};
    std::string s = "abacbe";
    REQUIRE(3 == Solution::longestPath(parent, s));
  }
  {
    std::vector<int> parent{-1, 0, 0, 0};
    std::string s = "aabc";
    REQUIRE(3 == Solution::longestPath(parent, s));
  }
}

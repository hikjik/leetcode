#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> cookies{8, 15, 10, 20, 8};
    REQUIRE(31 == Solution::distributeCookies(cookies, k));
  }
  {
    int k = 3;
    std::vector<int> cookies{6, 1, 3, 2, 2, 4, 1, 2};
    REQUIRE(7 == Solution::distributeCookies(cookies, k));
  }
}

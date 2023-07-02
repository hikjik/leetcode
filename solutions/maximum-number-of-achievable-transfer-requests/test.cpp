#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 5;
    std::vector<std::vector<int>> requests{{0, 1}, {1, 0}, {0, 1},
                                           {1, 2}, {2, 0}, {3, 4}};
    REQUIRE(5 == Solution::maximumRequests(n, requests));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> requests{{0, 0}, {1, 2}, {2, 1}};
    REQUIRE(3 == Solution::maximumRequests(n, requests));
  }
  {
    int n = 4;
    std::vector<std::vector<int>> requests{{0, 3}, {3, 1}, {1, 2}, {2, 0}};
    REQUIRE(4 == Solution::maximumRequests(n, requests));
  }
}
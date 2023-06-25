#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int start = 1, finish = 3, fuel = 5;
    std::vector<int> locations{2, 3, 6, 8, 4};
    REQUIRE(4 == Solution::countRoutes(locations, start, finish, fuel));
  }
  {
    int start = 1, finish = 0, fuel = 6;
    std::vector<int> locations{4, 3, 1};
    REQUIRE(5 == Solution::countRoutes(locations, start, finish, fuel));
  }
  {
    int start = 0, finish = 2, fuel = 3;
    std::vector<int> locations{5, 2, 1};
    REQUIRE(0 == Solution::countRoutes(locations, start, finish, fuel));
  }
}

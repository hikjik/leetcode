#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> rooms{{1}, {2}, {3}, {}};
    REQUIRE(Solution::canVisitAllRooms(rooms));
  }
  {
    std::vector<std::vector<int>> rooms{{1, 3}, {3, 0, 1}, {2}, {0}};
    REQUIRE_FALSE(Solution::canVisitAllRooms(rooms));
  }
}

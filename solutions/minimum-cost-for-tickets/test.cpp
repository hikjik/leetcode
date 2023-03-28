#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> days{1, 4, 6, 7, 8, 20};
    std::vector<int> costs{2, 7, 15};
    REQUIRE(11 == Solution::mincostTickets(days, costs));
  }
  {
    std::vector<int> days{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    std::vector<int> costs{2, 7, 15};
    REQUIRE(17 == Solution::mincostTickets(days, costs));
  }
}

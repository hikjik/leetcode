#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> bills{5, 5, 5, 10, 20};
    REQUIRE(Solution::lemonadeChange(bills));
  }
  {
    std::vector<int> bills{5, 5, 10, 10, 20};
    REQUIRE_FALSE(Solution::lemonadeChange(bills));
  }
}

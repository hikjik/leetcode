#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> coins{1, 2, 5};
    int amount = 5;
    REQUIRE(4 == Solution::change(amount, coins));
  }
  {
    std::vector<int> coins{2};
    int amount = 3;
    REQUIRE(0 == Solution::change(amount, coins));
  }
  {
    std::vector<int> coins{10};
    int amount = 10;
    REQUIRE(1 == Solution::change(amount, coins));
  }
}

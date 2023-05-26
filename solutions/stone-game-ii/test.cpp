#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> piles{2, 7, 9, 4, 4};
    REQUIRE(10 == Solution().stoneGameII(piles));
  }
  {
    std::vector<int> piles{1, 2, 3, 4, 5, 100};
    REQUIRE(104 == Solution().stoneGameII(piles));
  }
}

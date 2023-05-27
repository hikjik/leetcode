#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> stone_values{1, 2, 3, 7};
    REQUIRE("Bob" == Solution().stoneGameIII(stone_values));
  }
  {

    std::vector<int> stone_values{1, 2, 3, -9};
    REQUIRE("Alice" == Solution().stoneGameIII(stone_values));
  }
  {
    std::vector<int> stone_values{1, 2, 3, 6};
    REQUIRE("Tie" == Solution().stoneGameIII(stone_values));
  }
}

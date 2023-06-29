#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> grid{"@.a..", "###.#", "b.A.B"};
    REQUIRE(8 == Solution::shortestPathAllKeys(grid));
  }
  {
    std::vector<std::string> grid{"@..aA", "..B#.", "....b"};
    REQUIRE(6 == Solution::shortestPathAllKeys(grid));
  }
  {
    std::vector<std::string> grid{"@Aa"};
    REQUIRE(-1 == Solution::shortestPathAllKeys(grid));
  }
}

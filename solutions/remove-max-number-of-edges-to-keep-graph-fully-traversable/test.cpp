#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 4;
    std::vector<std::vector<int>> edges{{3, 1, 2}, {3, 2, 3}, {1, 1, 3},
                                        {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    REQUIRE(2 == Solution::maxNumEdgesToRemove(n, edges));
  }
  {
    int n = 4;
    std::vector<std::vector<int>> edges{
        {3, 1, 2}, {3, 2, 3}, {1, 1, 4}, {2, 1, 4}};
    REQUIRE(0 == Solution::maxNumEdgesToRemove(n, edges));
  }
  {
    int n = 4;
    std::vector<std::vector<int>> edges{{3, 2, 3}, {1, 1, 2}, {2, 3, 4}};
    REQUIRE(-1 == Solution::maxNumEdgesToRemove(n, edges));
  }
}

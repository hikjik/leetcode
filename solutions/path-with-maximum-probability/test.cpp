#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3;
    std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
    std::vector<double> succProb{0.5, 0.5, 0.2};
    int start = 0, end = 2;
    REQUIRE(0.25000 ==
            Solution::maxProbability(n, edges, succProb, start, end));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
    std::vector<double> succProb{0.5, 0.5, 0.3};
    int start = 0, end = 2;
    REQUIRE(0.30000 ==
            Solution::maxProbability(n, edges, succProb, start, end));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> edges{{0, 1}};
    std::vector<double> succProb{0.5};
    int start = 0, end = 2;
    REQUIRE(0.00000 ==
            Solution::maxProbability(n, edges, succProb, start, end));
  }
}

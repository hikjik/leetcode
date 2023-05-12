#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> questions{{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    REQUIRE(5 == Solution::mostPoints(questions));
  }
  {
    std::vector<std::vector<int>> questions{
        {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    REQUIRE(7 == Solution::mostPoints(questions));
  }
}

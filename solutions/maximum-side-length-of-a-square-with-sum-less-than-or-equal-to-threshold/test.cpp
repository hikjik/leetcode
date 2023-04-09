#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int threshold = 4;
    std::vector<std::vector<int>> mat{
        {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};
    REQUIRE(2 == Solution::maxSideLength(mat, threshold));
  }
  {
    int threshold = 1;
    std::vector<std::vector<int>> mat{{2, 2, 2, 2, 2},
                                      {2, 2, 2, 2, 2},
                                      {2, 2, 2, 2, 2},
                                      {2, 2, 2, 2, 2},
                                      {2, 2, 2, 2, 2}};
    REQUIRE(0 == Solution::maxSideLength(mat, threshold));
  }
}

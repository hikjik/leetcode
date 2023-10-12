#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> matrix{{3, 0, 1, 4, 2},
                                         {5, 6, 3, 2, 1},
                                         {1, 2, 0, 1, 5},
                                         {4, 1, 0, 1, 7},
                                         {1, 0, 3, 0, 5}};
    auto num_matrix = NumMatrix(matrix);

    REQUIRE(8 == num_matrix.sumRegion(2, 1, 4, 3));
    REQUIRE(11 == num_matrix.sumRegion(1, 1, 2, 2));
    REQUIRE(12 == num_matrix.sumRegion(1, 2, 2, 4));
  }
}

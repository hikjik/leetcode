#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<std::vector<int>> nums{{3, 0, 1, 4, 2},
                                     {5, 6, 3, 2, 1},
                                     {1, 2, 0, 1, 5},
                                     {4, 1, 0, 1, 7},
                                     {1, 0, 3, 0, 5}};
  auto mat = new NumMatrix(nums);
  REQUIRE(8 == mat->sumRegion(2, 1, 4, 3));
  REQUIRE(11 == mat->sumRegion(1, 1, 2, 2));
  REQUIRE(12 == mat->sumRegion(1, 2, 2, 4));
}

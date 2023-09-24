#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int poured = 1, query_row = 1, query_glass = 1;
    const auto actual =
        Solution::champagneTower(poured, query_row, query_glass);
    REQUIRE(0.00000 == Approx(actual));
  }
  {
    int poured = 2, query_row = 1, query_glass = 1;
    const auto actual =
        Solution::champagneTower(poured, query_row, query_glass);
    REQUIRE(0.50000 == Approx(actual));
  }
  {
    int poured = 100000009, query_row = 33, query_glass = 17;
    const auto actual =
        Solution::champagneTower(poured, query_row, query_glass);
    REQUIRE(1.00000 == Approx(actual));
  }
  {
    int poured = 25, query_row = 6, query_glass = 1;
    const auto actual =
        Solution::champagneTower(poured, query_row, query_glass);
    REQUIRE(0.18750 == Approx(actual));
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                          {'1', '0', '1', '1', '1'},
                                          {'1', '1', '1', '1', '1'},
                                          {'1', '0', '0', '1', '0'}};
    REQUIRE(4 == Solution::maximalSquare(matrix));
  }
  {
    std::vector<std::vector<char>> matrix{{'0', '1'}, {'1', '0'}};
    REQUIRE(1 == Solution::maximalSquare(matrix));
  }
  {
    std::vector<std::vector<char>> matrix{{'0'}};
    REQUIRE(0 == Solution::maximalSquare(matrix));
  }
}

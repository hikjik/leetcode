#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> nums{1, 2, 3, 6, 9, 8, 7, 4, 5};
    REQUIRE(nums == Solution::spiralOrder(matrix));
  }
  {
    std::vector<std::vector<int>> matrix{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    std::vector<int> nums{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    REQUIRE(nums == Solution::spiralOrder(matrix));
  }
  {
    std::vector<std::vector<int>> matrix{{1, 2, 3, 4}};
    std::vector<int> nums{1, 2, 3, 4};
    REQUIRE(nums == Solution::spiralOrder(matrix));
  }
  {
    std::vector<std::vector<int>> matrix{{1}, {2}, {3}, {4}};
    std::vector<int> nums{1, 2, 3, 4};
    REQUIRE(nums == Solution::spiralOrder(matrix));
  }
  {
    std::vector<std::vector<int>> matrix{{1}};
    std::vector<int> nums{1};
    REQUIRE(nums == Solution::spiralOrder(matrix));
  }
}

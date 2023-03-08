#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> first_list{
        {0, 2}, {5, 10}, {13, 23}, {24, 25}};
    std::vector<std::vector<int>> second_list{
        {1, 5}, {8, 12}, {15, 24}, {25, 26}};
    std::vector<std::vector<int>> intersections{{1, 2},   {5, 5},   {8, 10},
                                                {15, 23}, {24, 24}, {25, 25}};
    REQUIRE(intersections ==
            Solution::intervalIntersection(first_list, second_list));
  }
  {
    std::vector<std::vector<int>> first_list{{1, 3}, {5, 9}};
    std::vector<std::vector<int>> second_list;
    std::vector<std::vector<int>> intersections;
    REQUIRE(intersections ==
            Solution::intervalIntersection(first_list, second_list));
  }
  {
    std::vector<std::vector<int>> first_list{{5, 10}};
    std::vector<std::vector<int>> second_list{{5, 6}};
    std::vector<std::vector<int>> intersections{{5, 6}};
    REQUIRE(intersections ==
            Solution::intervalIntersection(first_list, second_list));
  }
}

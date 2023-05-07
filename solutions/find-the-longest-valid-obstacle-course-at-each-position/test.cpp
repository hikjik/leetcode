#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> obstacles{1, 2, 3, 2};
    std::vector<int> expected{1, 2, 3, 3};
    REQUIRE(expected ==
            Solution::longestObstacleCourseAtEachPosition(obstacles));
  }
  {
    std::vector<int> obstacles{2, 2, 1};
    std::vector<int> expected{1, 2, 1};
    REQUIRE(expected ==
            Solution::longestObstacleCourseAtEachPosition(obstacles));
  }
  {

    std::vector<int> obstacles{3, 1, 5, 6, 4, 2};
    std::vector<int> expected{1, 1, 2, 3, 2, 2};
    REQUIRE(expected ==
            Solution::longestObstacleCourseAtEachPosition(obstacles));
  }
}

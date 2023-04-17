#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites{{1, 0}};
    REQUIRE(Solution::canFinish(numCourses, prerequisites));
  }
  {
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites{{1, 0}, {0, 1}};
    REQUIRE_FALSE(Solution::canFinish(numCourses, prerequisites));
  }
}

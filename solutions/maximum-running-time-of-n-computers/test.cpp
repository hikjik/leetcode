#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 2;
    std::vector<int> batteries{3, 3, 3};
    REQUIRE(4 == Solution::maxRunTime(n, batteries));
  }
  {
    int n = 2;
    std::vector<int> batteries{1, 1, 1, 1};
    REQUIRE(2 == Solution::maxRunTime(n, batteries));
  }
  {
    int n = 3;
    std::vector<int> batteries{10, 10, 3, 5};
    REQUIRE(8 == Solution::maxRunTime(n, batteries));
  }
}

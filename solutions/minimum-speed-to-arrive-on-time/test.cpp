#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    double hour = 6;
    std::vector<int> dist{1, 3, 2};
    REQUIRE(1 == Solution::minSpeedOnTime(dist, hour));
  }
  {
    double hour = 2.7;
    std::vector<int> dist{1, 3, 2};
    REQUIRE(3 == Solution::minSpeedOnTime(dist, hour));
  }
  {
    double hour = 1.9;
    std::vector<int> dist{1, 3, 2};
    REQUIRE(-1 == Solution::minSpeedOnTime(dist, hour));
  }
  {
    double hour = 0.01;
    std::vector<int> dist{100000};
    REQUIRE(10000000 == Solution::minSpeedOnTime(dist, hour));
  }
  {
    double hour = 1.0;
    std::vector<int> dist{1, 1};
    REQUIRE(-1 == Solution::minSpeedOnTime(dist, hour));
  }
  {
    double hour = 2.03;
    std::vector<int> dist{4, 2, 3};
    REQUIRE(100 == Solution::minSpeedOnTime(dist, hour));
  }
}

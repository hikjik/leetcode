#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> time{1, 2, 3};
    int total_trips = 5;
    REQUIRE(3 == Solution::minimumTime(time, total_trips));
  }
  {
    std::vector<int> time{2};
    int total_trips = 1;
    REQUIRE(2 == Solution::minimumTime(time, total_trips));
  }
  {
    std::vector<int> time{10000000};
    int total_trips = 10000000;
    REQUIRE(1e14 == Solution::minimumTime(time, total_trips));
  }
}

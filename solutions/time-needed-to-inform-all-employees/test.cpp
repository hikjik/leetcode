#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 1;
    int head_id = 0;
    std::vector<int> manager{-1};
    std::vector<int> inform_time{0};
    REQUIRE(0 == Solution::numOfMinutes(n, head_id, manager, inform_time));
  }
  {
    int n = 6;
    int head_id = 2;
    std::vector<int> manager{2, 2, -1, 2, 2, 2};
    std::vector<int> inform_time{0, 0, 1, 0, 0, 0};
    REQUIRE(1 == Solution::numOfMinutes(n, head_id, manager, inform_time));
  }
}

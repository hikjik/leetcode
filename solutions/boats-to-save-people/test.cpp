#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int limit = 3;
    std::vector<int> people{1, 2};
    REQUIRE(1 == Solution::numRescueBoats(people, limit));
  }
  {
    int limit = 3;
    std::vector<int> people{3, 2, 2, 1};
    REQUIRE(3 == Solution::numRescueBoats(people, limit));
  }
  {
    int limit = 5;
    std::vector<int> people{3, 5, 3, 4};
    REQUIRE(4 == Solution::numRescueBoats(people, limit));
  }
}

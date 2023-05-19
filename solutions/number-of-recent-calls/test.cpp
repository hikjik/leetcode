#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  RecentCounter recentCounter;
  REQUIRE(1 == recentCounter.ping(1));
  REQUIRE(2 == recentCounter.ping(100));
  REQUIRE(3 == recentCounter.ping(3001));
  REQUIRE(3 == recentCounter.ping(3002));
}

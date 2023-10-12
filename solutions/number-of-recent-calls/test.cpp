#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto recent_counter = RecentCounter();

  REQUIRE(1 == recent_counter.ping(1));
  REQUIRE(2 == recent_counter.ping(100));
  REQUIRE(3 == recent_counter.ping(3001));
  REQUIRE(3 == recent_counter.ping(3002));
}

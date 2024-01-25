#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {

    auto hit_counter = HitCounter();

    hit_counter.hit(1);
    hit_counter.hit(2);
    hit_counter.hit(3);
    REQUIRE(3 == hit_counter.getHits(4));
    hit_counter.hit(300);
    REQUIRE(4 == hit_counter.getHits(300));
    REQUIRE(3 == hit_counter.getHits(301));
  }
}

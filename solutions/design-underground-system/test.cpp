#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    REQUIRE(14.00000 ==
            undergroundSystem.getAverageTime("Paradise", "Cambridge"));
    REQUIRE(11.00000 ==
            Approx(undergroundSystem.getAverageTime("Leyton", "Waterloo")));
    undergroundSystem.checkIn(10, "Leyton", 24);
    REQUIRE(11.00000 ==
            Approx(undergroundSystem.getAverageTime("Leyton", "Waterloo")));
    undergroundSystem.checkOut(10, "Waterloo", 38);
    REQUIRE(12.00000 ==
            Approx(undergroundSystem.getAverageTime("Leyton", "Waterloo")));
  }
  {
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(10, "Leyton", 3);
    undergroundSystem.checkOut(10, "Paradise", 8);
    REQUIRE(5.00000 ==
            Approx(undergroundSystem.getAverageTime("Leyton", "Paradise")));
    undergroundSystem.checkIn(5, "Leyton", 10);
    undergroundSystem.checkOut(5, "Paradise", 16);
    REQUIRE(5.50000 ==
            Approx(undergroundSystem.getAverageTime("Leyton", "Paradise")));
    undergroundSystem.checkIn(2, "Leyton", 21);
    undergroundSystem.checkOut(2, "Paradise", 30);
    REQUIRE(6.66667 ==
            Approx(undergroundSystem.getAverageTime("Leyton", "Paradise")));
  }
}

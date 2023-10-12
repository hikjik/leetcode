#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    auto underground_system = UndergroundSystem();

    underground_system.checkIn(45, "Leyton", 3);
    underground_system.checkIn(32, "Paradise", 8);
    underground_system.checkIn(27, "Leyton", 10);
    underground_system.checkOut(45, "Waterloo", 15);
    underground_system.checkOut(27, "Waterloo", 20);
    underground_system.checkOut(32, "Cambridge", 22);
    REQUIRE(14.0 ==
            Approx(underground_system.getAverageTime("Paradise", "Cambridge")));
    REQUIRE(11.0 ==
            Approx(underground_system.getAverageTime("Leyton", "Waterloo")));
    underground_system.checkIn(10, "Leyton", 24);
    REQUIRE(11.0 ==
            Approx(underground_system.getAverageTime("Leyton", "Waterloo")));
    underground_system.checkOut(10, "Waterloo", 38);
    REQUIRE(12.0 ==
            Approx(underground_system.getAverageTime("Leyton", "Waterloo")));
  }
  {
    auto underground_system = UndergroundSystem();

    underground_system.checkIn(10, "Leyton", 3);
    underground_system.checkOut(10, "Paradise", 8);
    REQUIRE(5.0 ==
            Approx(underground_system.getAverageTime("Leyton", "Paradise")));
    underground_system.checkIn(5, "Leyton", 10);
    underground_system.checkOut(5, "Paradise", 16);
    REQUIRE(5.5 ==
            Approx(underground_system.getAverageTime("Leyton", "Paradise")));
    underground_system.checkIn(2, "Leyton", 21);
    underground_system.checkOut(2, "Paradise", 30);
    REQUIRE(6.66667 ==
            Approx(underground_system.getAverageTime("Leyton", "Paradise")));
  }
}

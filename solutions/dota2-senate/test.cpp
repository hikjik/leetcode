#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("Radiant" == Solution::predictPartyVictory("RD"));
  REQUIRE("Dire" == Solution::predictPartyVictory("RDD"));
  REQUIRE("Dire" == Solution::predictPartyVictory("DDRRR"));
  REQUIRE("Dire" == Solution::predictPartyVictory(
                        "DDDDRRDDDRDRDRRDDRDDDRDRRRRDRRRRRDRDDRDDRRDDRRRDDRRRDD"
                        "DDRRRRRRRDDRRRDDRDDDRRRDRDDRDDDRRDRRDRRRDRDRDR"));
}

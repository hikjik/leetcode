#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<int> persons{0, 1, 1, 0, 0, 1, 0};
  std::vector<int> times{0, 5, 10, 15, 20, 25, 30};
  TopVotedCandidate top(persons, times);

  REQUIRE(0 == top.q(3));
  REQUIRE(1 == top.q(12));
  REQUIRE(1 == top.q(25));
  REQUIRE(0 == top.q(15));
  REQUIRE(0 == top.q(24));
  REQUIRE(1 == top.q(8));
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto randomized_set = RandomizedSet();

  REQUIRE(true == randomized_set.insert(1));
  REQUIRE(false == randomized_set.remove(2));
  REQUIRE(true == randomized_set.insert(2));

  const auto r = randomized_set.getRandom();
  REQUIRE(r >= 1);
  REQUIRE(r <= 2);

  REQUIRE(true == randomized_set.remove(1));
  REQUIRE(false == randomized_set.insert(2));

  REQUIRE(2 == randomized_set.getRandom());
}

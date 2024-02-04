#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto collection = RandomizedCollection();

  REQUIRE(collection.insert(1));
  REQUIRE_FALSE(collection.insert(1));
  REQUIRE(collection.insert(2));

  const auto r = collection.getRandom();
  REQUIRE(r >= 1);
  REQUIRE(r <= 2);

  REQUIRE(collection.remove(2));
  REQUIRE(1 == collection.getRandom());
}

TEST_CASE("Test Remove") {
  RandomizedCollection collection;

  REQUIRE(collection.insert(1));
  REQUIRE_FALSE(collection.insert(1));
  REQUIRE(collection.insert(2));
  REQUIRE_FALSE(collection.insert(2));
  REQUIRE(collection.insert(3));
  REQUIRE_FALSE(collection.insert(3));

  REQUIRE(collection.remove(1));
  REQUIRE(collection.remove(2));
  REQUIRE(collection.remove(2));
  REQUIRE(collection.remove(1));
  REQUIRE(collection.remove(3));

  REQUIRE(collection.insert(4));

  REQUIRE(collection.remove(3));

  REQUIRE(4 == collection.getRandom());
  REQUIRE(4 == collection.getRandom());
  REQUIRE(4 == collection.getRandom());
  REQUIRE(4 == collection.getRandom());
  REQUIRE(4 == collection.getRandom());
  REQUIRE(4 == collection.getRandom());
}

TEST_CASE("Empty") {
  RandomizedCollection collection;

  REQUIRE(collection.insert(1));
  REQUIRE(collection.remove(1));
  REQUIRE(collection.insert(1));
}

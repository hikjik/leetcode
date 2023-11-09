#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Recursion") {
  Tree root{7, 3, 15, std::nullopt, std::nullopt, 9, 20};
  auto iterator = recursion::BSTIterator(root);

  REQUIRE(3 == iterator.next());
  REQUIRE(7 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(9 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(15 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(20 == iterator.next());
  REQUIRE(false == iterator.hasNext());
}

TEST_CASE("Stack") {
  Tree root{7, 3, 15, std::nullopt, std::nullopt, 9, 20};
  auto iterator = stack::BSTIterator(root);

  REQUIRE(3 == iterator.next());
  REQUIRE(7 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(9 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(15 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(20 == iterator.next());
  REQUIRE(false == iterator.hasNext());
}

TEST_CASE("Morris") {
  Tree root{7, 3, 15, std::nullopt, std::nullopt, 9, 20};
  auto iterator = morris::BSTIterator(root);

  REQUIRE(3 == iterator.next());
  REQUIRE(7 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(9 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(15 == iterator.next());
  REQUIRE(true == iterator.hasNext());
  REQUIRE(20 == iterator.next());
  REQUIRE(false == iterator.hasNext());
}

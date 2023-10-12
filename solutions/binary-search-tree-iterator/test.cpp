#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    Tree root{7, 3, 15, std::nullopt, std::nullopt, 9, 20};
    auto iterator = BSTIterator(root);

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
}

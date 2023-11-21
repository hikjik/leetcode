#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<int> nums{1, 2, 3};
  PeekingIterator iterator(nums);
  REQUIRE(1 == iterator.next());
  REQUIRE(2 == iterator.peek());
  REQUIRE(2 == iterator.next());
  REQUIRE(3 == iterator.next());
  REQUIRE(false == iterator.hasNext());
}

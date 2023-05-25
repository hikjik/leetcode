#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  KthLargest kthLargest(3, std::vector<int>{4, 5, 8, 2});
  REQUIRE(4 == kthLargest.add(3));
  REQUIRE(5 == kthLargest.add(5));
  REQUIRE(5 == kthLargest.add(10));
  REQUIRE(8 == kthLargest.add(9));
  REQUIRE(8 == kthLargest.add(4));
}

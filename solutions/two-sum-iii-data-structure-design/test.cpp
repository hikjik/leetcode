#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto two_sum = TwoSum();

  two_sum.add(1);
  two_sum.add(3);
  two_sum.add(5);
  REQUIRE(true == two_sum.find(4));
  REQUIRE(false == two_sum.find(7));
}

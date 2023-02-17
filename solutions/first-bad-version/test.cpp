#include <catch.hpp>

#include <solution.hpp>

#include <limits>

TEST_CASE("Simple") {
  int n = 5;
  REQUIRE(4 == Solution::firstBadVersion(n));
}

TEST_CASE("Big") {
  int n = std::numeric_limits<int>::max();
  REQUIRE(4 == Solution::firstBadVersion(n));
}

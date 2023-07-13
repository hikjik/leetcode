#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("PAHNAPLSIIGYIR" == Solution::convert("PAYPALISHIRING", 3));
  REQUIRE("PINALSIGYAHRPI" == Solution::convert("PAYPALISHIRING", 4));
  REQUIRE("A" == Solution::convert("A", 1));
  REQUIRE("ABC" == Solution::convert("ABC", 1));
}

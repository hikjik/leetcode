#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("6" == Solution::multiply("2", "3"));
  REQUIRE("56088" == Solution::multiply("123", "456"));
  REQUIRE("0" == Solution::multiply("123", "0"));
  REQUIRE("0" == Solution::multiply("1", "0"));
}

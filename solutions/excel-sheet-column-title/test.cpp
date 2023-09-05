#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("A" == Solution().convertToTitle(1));
  REQUIRE("AB" == Solution().convertToTitle(28));
  REQUIRE("ZY" == Solution().convertToTitle(701));
}

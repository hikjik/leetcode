#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("Goal" == Solution::interpret("G()(al)"));
  REQUIRE("Gooooal" == Solution::interpret("G()()()()(al)"));
  REQUIRE("alGalooG" == Solution::interpret("(al)G(al)()()G"));
}

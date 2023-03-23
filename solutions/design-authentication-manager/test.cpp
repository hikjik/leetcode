#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  AuthenticationManager manager(5);
  manager.renew("aaa", 1);
  manager.generate("aaa", 2);
  REQUIRE(1 == manager.countUnexpiredTokens(6));
  manager.generate("bbb", 7);
  manager.renew("aaa", 8);
  manager.renew("bbb", 10);
  REQUIRE(0 == manager.countUnexpiredTokens(15));
}

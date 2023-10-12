#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int timeToLive = 5;
  auto authentication_manager = AuthenticationManager(timeToLive);

  authentication_manager.renew("aaa", 1);
  authentication_manager.generate("aaa", 2);
  REQUIRE(1 == authentication_manager.countUnexpiredTokens(6));
  authentication_manager.generate("bbb", 7);
  authentication_manager.renew("aaa", 8);
  authentication_manager.renew("bbb", 10);
  REQUIRE(0 == authentication_manager.countUnexpiredTokens(15));
}

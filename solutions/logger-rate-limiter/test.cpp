#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  Logger logger;
  REQUIRE(true == logger.shouldPrintMessage(1, "foo"));
  REQUIRE(true == logger.shouldPrintMessage(2, "bar"));
  REQUIRE(false == logger.shouldPrintMessage(3, "foo"));
  REQUIRE(false == logger.shouldPrintMessage(8, "bar"));
  REQUIRE(false == logger.shouldPrintMessage(10, "foo"));
  REQUIRE(true == logger.shouldPrintMessage(11, "foo"));
}

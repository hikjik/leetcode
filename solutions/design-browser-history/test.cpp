#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto obj = new BrowserHistory("leetcode.com");
  obj->visit("google.com");
  obj->visit("facebook.com");
  obj->visit("youtube.com");
  REQUIRE("facebook.com" == obj->back(1));
  REQUIRE("google.com" == obj->back(1));
  REQUIRE("facebook.com" == obj->forward(1));
  obj->visit("linkedin.com");
  REQUIRE("linkedin.com" == obj->forward(2));
  REQUIRE("google.com" == obj->back(2));
  REQUIRE("leetcode.com" == obj->back(7));
}

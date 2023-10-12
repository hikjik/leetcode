#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::string homepage = "leetcode.com";
  auto browser_history = BrowserHistory(homepage);

  browser_history.visit("google.com");
  browser_history.visit("facebook.com");
  browser_history.visit("youtube.com");
  REQUIRE("facebook.com" == browser_history.back(1));
  REQUIRE("google.com" == browser_history.back(1));
  REQUIRE("facebook.com" == browser_history.forward(1));
  browser_history.visit("linkedin.com");
  REQUIRE("linkedin.com" == browser_history.forward(2));
  REQUIRE("google.com" == browser_history.back(2));
  REQUIRE("leetcode.com" == browser_history.back(7));
}

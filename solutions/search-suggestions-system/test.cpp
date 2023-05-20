#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> products{"mobile", "mouse", "moneypot", "monitor",
                                      "mousepad"};
    std::string searchWord = "mouse";
    std::vector<std::vector<std::string>> expected{
        {"mobile", "moneypot", "monitor"},
        {"mobile", "moneypot", "monitor"},
        {"mouse", "mousepad"},
        {"mouse", "mousepad"},
        {"mouse", "mousepad"}};
    REQUIRE(expected == Solution::suggestedProducts(products, searchWord));
  }
  {
    std::vector<std::string> products{"havana"};
    std::string searchWord = "havana";
    std::vector<std::vector<std::string>> expected{
        {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}};
    REQUIRE(expected == Solution::suggestedProducts(products, searchWord));
  }
}

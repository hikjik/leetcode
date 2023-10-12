#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> products;
    std::string searchWord;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .products{"mobile", "mouse", "moneypot", "monitor", "mousepad"},
          .searchWord = "mouse",
          .expected{{"mobile", "moneypot", "monitor"},
                    {"mobile", "moneypot", "monitor"},
                    {"mouse", "mousepad"},
                    {"mouse", "mousepad"},
                    {"mouse", "mousepad"}},
      },
      {
          .products{"havana"},
          .searchWord = "havana",
          .expected{{"havana"},
                    {"havana"},
                    {"havana"},
                    {"havana"},
                    {"havana"},
                    {"havana"}},
      },
  };

  for (const auto &[products, searchWord, expected] : test_cases) {
    const auto actual = Solution::suggestedProducts(products, searchWord);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> urls;
    std::vector<std::vector<int>> edges;
    std::string startUrl;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .urls{
              "http://news.yahoo.com",
              "http://news.yahoo.com/news",
              "http://news.yahoo.com/news/topics/",
              "http://news.google.com",
              "http://news.yahoo.com/us",
          },
          .edges{{2, 0}, {2, 1}, {3, 2}, {3, 1}, {0, 4}},
          .startUrl = "http://news.yahoo.com/news/topics/",
          .expected{
              "http://news.yahoo.com",
              "http://news.yahoo.com/news",
              "http://news.yahoo.com/news/topics/",
              "http://news.yahoo.com/us",
          },
      },
      {
          .urls{
              "http://news.yahoo.com",
              "http://news.yahoo.com/news",
              "http://news.yahoo.com/news/topics/",
              "http://news.google.com",
          },
          .edges{{0, 2}, {2, 1}, {3, 2}, {3, 1}, {3, 0}},
          .startUrl = "http://news.google.com",
          .expected{"http://news.google.com"},
      },
  };

  for (const auto &[urls, edges, startUrl, expected] : test_cases) {
    HtmlParser parser(urls, edges);
    const auto actual = Solution::crawl(startUrl, parser);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}

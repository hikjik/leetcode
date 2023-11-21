#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto twitter = Twitter();

  twitter.postTweet(1, 5);
  REQUIRE(std::vector<int>{5} == twitter.getNewsFeed(1));
  twitter.follow(1, 2);
  twitter.postTweet(2, 6);
  REQUIRE(std::vector<int>{6, 5} == twitter.getNewsFeed(1));
  twitter.unfollow(1, 2);
  REQUIRE(std::vector<int>{5} == twitter.getNewsFeed(1));
}

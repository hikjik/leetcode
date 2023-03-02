#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<std::string> words{"i", "love", "leetcode",
                                   "i", "love", "coding"};
    std::vector<std::string> expected{"i", "love"};
    REQUIRE(expected == Solution::topKFrequent(words, k));
  }
  {
    int k = 4;
    std::vector<std::string> words{"the", "day", "is",    "sunny", "the",
                                   "the", "the", "sunny", "is",    "is"};
    std::vector<std::string> expected{"the", "is", "sunny", "day"};
    REQUIRE(expected == Solution::topKFrequent(words, k));
  }
}

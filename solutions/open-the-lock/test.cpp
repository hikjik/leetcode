#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::string target = "0202";
    std::vector<std::string> deadends{"0201", "0101", "0102", "1212", "2002"};
    REQUIRE(6 == Solution::openLock(deadends, target));
  }
  {
    std::string target = "0009";
    std::vector<std::string> deadends{"8888"};
    REQUIRE(1 == Solution::openLock(deadends, target));
  }
  {
    std::string target = "8888";
    std::vector<std::string> deadends{"8887", "8889", "8878", "8898",
                                      "8788", "8988", "7888", "9888"};
    REQUIRE(-1 == Solution::openLock(deadends, target));
  }
  {
    std::string target = "8888";
    std::vector<std::string> deadends{"0000"};
    REQUIRE(-1 == Solution::openLock(deadends, target));
  }
}

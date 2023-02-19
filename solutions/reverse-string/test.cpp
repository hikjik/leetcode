#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<char> str{'h', 'e', 'l', 'l', 'o'};
    std::vector<char> expected{'o', 'l', 'l', 'e', 'h'};
    Solution::reverseString(str);
    REQUIRE(expected == str);
  }
  {
    std::vector<char> str{'H', 'a', 'n', 'n', 'a', 'h'};
    std::vector<char> expected{'h', 'a', 'n', 'n', 'a', 'H'};
    Solution::reverseString(str);
    REQUIRE(expected == str);
  }
}

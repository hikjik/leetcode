#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<char> letters{'c', 'f', 'j'};
    REQUIRE('c' == Solution::nextGreatestLetter(letters, 'a'));
  }
  {
    std::vector<char> letters{'c', 'f', 'j'};
    REQUIRE('f' == Solution::nextGreatestLetter(letters, 'c'));
  }
  {
    std::vector<char> letters{'x', 'x', 'y', 'y'};
    REQUIRE('x' == Solution::nextGreatestLetter(letters, 'z'));
  }
}

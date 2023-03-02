#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    std::vector<char> expected{'a', '2', 'b', '2', 'c', '3'};
    int pos = 6;
    REQUIRE(pos == Solution::compress(chars));
    chars.erase(chars.begin() + pos, chars.end());
    REQUIRE(chars.size() == size_t(pos));
    REQUIRE(expected == chars);
  }
  {
    std::vector<char> chars{'a'};
    std::vector<char> expected{'a'};
    int pos = 1;
    REQUIRE(pos == Solution::compress(chars));
    chars.erase(chars.begin() + pos, chars.end());
    REQUIRE(chars.size() == size_t(pos));
    REQUIRE(expected == chars);
  }
  {
    std::vector<char> chars{'a', 'b', 'b', 'b', 'b', 'b', 'b',
                            'b', 'b', 'b', 'b', 'b', 'b'};
    std::vector<char> expected{'a', 'b', '1', '2'};
    int pos = 4;
    REQUIRE(pos == Solution::compress(chars));
    chars.erase(chars.begin() + pos, chars.end());
    REQUIRE(chars.size() == size_t(pos));
    REQUIRE(expected == chars);
  }
  {
    std::vector<char> chars{'a', 'a', 'a', 'b', 'b', 'a', 'a'};
    std::vector<char> expected{'a', '3', 'b', '2', 'a', '2'};
    int pos = 6;
    REQUIRE(pos == Solution::compress(chars));
    chars.erase(chars.begin() + pos, chars.end());
    REQUIRE(chars.size() == size_t(pos));
    REQUIRE(expected == chars);
  }
}

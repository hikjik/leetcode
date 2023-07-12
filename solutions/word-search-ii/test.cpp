#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<char>> board{{'o', 'a', 'a', 'n'},
                                         {'e', 't', 'a', 'e'},
                                         {'i', 'h', 'k', 'r'},
                                         {'i', 'f', 'l', 'v'}};
    std::vector<std::string> words{"oath", "pea", "eat", "rain"};
    std::vector<std::string> expected{"oath", "eat"};
    REQUIRE(expected == Solution::findWords(board, words));
  }
  {
    std::vector<std::vector<char>> board{{'a', 'b'}, {'c', 'd'}};
    std::vector<std::string> words{"abcb"};
    std::vector<std::string> expected;
    REQUIRE(expected == Solution::findWords(board, words));
  }
}

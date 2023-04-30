#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> words{"dog", "cat", "dad", "good"};
    std::vector<char> letters{'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    std::vector<int> scores{1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
                            0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    REQUIRE(23 == Solution::maxScoreWords(words, letters, scores));
  }
  {
    std::vector<std::string> words{"xxxz", "ax", "bx", "cx"};
    std::vector<char> letters{'z', 'a', 'b', 'c', 'x', 'x', 'x'};
    std::vector<int> scores{4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};
    REQUIRE(27 == Solution::maxScoreWords(words, letters, scores));
  }
  {
    std::vector<std::string> words{"leetcode"};
    std::vector<char> letters{'l', 'e', 't', 'c', 'o', 'd'};
    std::vector<int> scores{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                            0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    REQUIRE(0 == Solution::maxScoreWords(words, letters, scores));
  }
}

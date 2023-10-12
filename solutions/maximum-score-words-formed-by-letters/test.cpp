#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::vector<char> letters;
    std::vector<int> score;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"dog", "cat", "dad", "good"},
          .letters{'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'},
          .score{1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
                 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          .expected = 23,
      },
      {
          .words{"xxxz", "ax", "bx", "cx"},
          .letters{'z', 'a', 'b', 'c', 'x', 'x', 'x'},
          .score{4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10},
          .expected = 27,
      },
      {
          .words{"leetcode"},
          .letters{'l', 'e', 't', 'c', 'o', 'd'},
          .score{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
          .expected = 0,
      },
  };

  for (const auto &[words, letters, score, expected] : test_cases) {
    const auto actual = Solution::maxScoreWords(words, letters, score);
    REQUIRE(expected == actual);
  }
}

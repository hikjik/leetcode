#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> board;
    std::vector<std::string> words;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .board{{'o', 'a', 'a', 'n'},
                 {'e', 't', 'a', 'e'},
                 {'i', 'h', 'k', 'r'},
                 {'i', 'f', 'l', 'v'}},
          .words{"oath", "pea", "eat", "rain"},
          .expected{"eat", "oath"},
      },
      {
          .board{{'a', 'b'}, {'c', 'd'}},
          .words{"abcb"},
          .expected{},
      },
  };

  for (const auto &[board, words, expected] : test_cases) {
    const auto actual = Solution::findWords(board, words);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}

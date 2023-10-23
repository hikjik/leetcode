#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> sentences;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sentences{"alice and bob love leetcode", "i think so too",
                     "this is great thanks very much"},
          .expected = 6,
      },
      {
          .sentences{"please wait", "continue to fight", "continue to win"},
          .expected = 3,
      },
  };

  for (const auto &[sentences, expected] : test_cases) {
    const auto actual = Solution::mostWordsFound(sentences);
    REQUIRE(expected == actual);
  }
}

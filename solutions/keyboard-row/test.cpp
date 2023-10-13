#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> words;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .words{"Hello", "Alaska", "Dad", "Peace"},
          .expected{"Alaska", "Dad"},
      },
      {
          .words{"omk"},
          .expected{},
      },
      {
          .words{"adsdf", "sfd"},
          .expected{"adsdf", "sfd"},
      },
  };

  for (const auto &[words, expected] : test_cases) {
    const auto actual = Solution::findWords(words);
    REQUIRE(expected == actual);
  }
}

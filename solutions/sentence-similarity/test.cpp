#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> sentence1;
    std::vector<std::string> sentence2;
    std::vector<std::vector<std::string>> similarPairs;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sentence1{"great", "acting", "skills"},
          .sentence2{"fine", "drama", "talent"},
          .similarPairs{
              {"great", "fine"}, {"drama", "acting"}, {"skills", "talent"}},
          .expected = true,
      },
      {
          .sentence1{"great"},
          .sentence2{"great"},
          .similarPairs{},
          .expected = true,
      },
      {
          .sentence1{"great"},
          .sentence2{"doubleplus", "good"},
          .similarPairs{{"great", "doubleplus"}},
          .expected = false,
      },
  };

  for (const auto &[sentence1, sentence2, similarPairs, expected] :
       test_cases) {
    const auto actual =
        Solution::areSentencesSimilar(sentence1, sentence2, similarPairs);
    REQUIRE(expected == actual);
  }
}

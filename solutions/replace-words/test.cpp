#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> dictionary;
    std::string sentence;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .dictionary{"cat", "bat", "rat"},
          .sentence = "the cattle was rattled by the battery",
          .expected = "the cat was rat by the bat",
      },
      {
          .dictionary{"a", "b", "c"},
          .sentence = "aadsfasf absbs bbab cadsfafs",
          .expected = "a a b c",
      },
  };

  for (const auto &[dictionary, sentence, expected] : test_cases) {
    const auto actual = Solution::replaceWords(dictionary, sentence);
    REQUIRE(expected == actual);
  }
}

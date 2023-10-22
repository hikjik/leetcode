#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string sentence;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .sentence = "thequickbrownfoxjumpsoverthelazydog",
          .expected = true,
      },
      {
          .sentence = "leetcode",
          .expected = false,
      },
  };

  for (const auto &[sentence, expected] : test_cases) {
    const auto actual = Solution::checkIfPangram(sentence);
    REQUIRE(expected == actual);
  }
}

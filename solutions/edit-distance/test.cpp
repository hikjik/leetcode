#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word1;
    std::string word2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word1 = "horse",
          .word2 = "ros",
          .expected = 3,
      },
      {
          .word1 = "intention",
          .word2 = "execution",
          .expected = 5,
      },
  };

  for (const auto &[word1, word2, expected] : test_cases) {
    const auto actual = Solution::minDistance(word1, word2);
    REQUIRE(expected == actual);
  }
}

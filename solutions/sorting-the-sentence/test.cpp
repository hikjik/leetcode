#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "is2 sentence4 This1 a3",
          .expected = "This is a sentence",
      },
      {
          .s = "Myself2 Me1 I4 and3",
          .expected = "Me Myself and I",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::sortSentence(s);
    REQUIRE(expected == actual);
  }
}

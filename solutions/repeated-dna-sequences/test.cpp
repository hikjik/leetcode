#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
          .expected{"AAAAACCCCC", "CCCCCAAAAA"},
      },
      {
          .s = "AAAAAAAAAAAAA",
          .expected{"AAAAAAAAAA"},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::findRepeatedDnaSequences(s);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}

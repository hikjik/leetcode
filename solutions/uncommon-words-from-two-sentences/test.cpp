#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "this apple is sweet",
          .s2 = "this apple is sour",
          .expected{"sweet", "sour"},
      },
      {
          .s1 = "apple apple",
          .s2 = "banana",
          .expected{"banana"},
      },
  };

  for (auto [s1, s2, expected] : test_cases) {
    auto actual = Solution::uncommonFromSentences(s1, s2);
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(expected == actual);
  }
}

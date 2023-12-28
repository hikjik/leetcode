#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "edaswf",
          .k = 1,
          .expected = 2,
      },
      {
          .s = "ltcrfrnesv",
          .k = 5,
          .expected = 5,
      },
      {
          .s = "rkyidomzyud",
          .k = 3,
          .expected = 4,
      },
      {
          .s = "acba",
          .k = 2,
          .expected = 2,
      },
      {
          .s = "abcac",
          .k = 2,
          .expected = 1,
      },
      {
          .s = "abcdef",
          .k = 2,
          .expected = 2,
      },
      {
          .s = "aabbaa",
          .k = 3,
          .expected = 0,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::minimumChanges(s, k);
    REQUIRE(expected == actual);
  }
}

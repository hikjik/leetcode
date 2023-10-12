#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aab",
          .expected = 0,
      },
      {
          .s = "aaabbbcc",
          .expected = 2,
      },
      {
          .s = "ceabaacb",
          .expected = 2,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::minDeletions(s);
    REQUIRE(expected == actual);
  }
}

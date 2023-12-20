#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcd",
          .k = 2,
          .expected = "abcd",
      },
      {
          .s = "deeedbbcccbdaa",
          .k = 3,
          .expected = "aa",
      },
      {
          .s = "pbbcggttciiippooaais",
          .k = 2,
          .expected = "ps",
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::removeDuplicates(s, k);
    REQUIRE(expected == actual);
  }
}

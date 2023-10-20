#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    char c;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "loveleetcode",
          .c = 'e',
          .expected{3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0},
      },
      {
          .s = "aaab",
          .c = 'b',
          .expected{3, 2, 1, 0},
      },
  };

  for (const auto &[s, c, expected] : test_cases) {
    const auto actual = Solution::shortestToChar(s, c);
    REQUIRE(expected == actual);
  }
}

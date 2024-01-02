#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<std::vector<int>> queries;
    std::vector<bool> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcabc",
          .queries{{1, 1, 3, 5}, {0, 2, 5, 5}},
          .expected{true, true},
      },
      {
          .s = "abbcdecbba",
          .queries{{0, 2, 7, 9}},
          .expected{false},
      },
      {
          .s = "acbcab",
          .queries{{1, 2, 4, 5}},
          .expected{true},
      },
      {
          .s = "odaxusaweuasuoeudxwa",
          .queries{{0, 5, 10, 14}},
          .expected{false},
      },
  };

  for (const auto &[s, queries, expected] : test_cases) {
    const auto actual = Solution::canMakePalindromeQueries(s, queries);
    REQUIRE(expected == actual);
  }
}

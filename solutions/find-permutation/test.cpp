#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "I",
          .expected{1, 2},
      },
      {
          .s = "DI",
          .expected{2, 1, 3},
      },
      {
          .s = "DIIDDDDIIDIIIID",
          .expected{2, 1, 3, 8, 7, 6, 5, 4, 9, 11, 10, 12, 13, 14, 16, 15},
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::findPermutation(s);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string word;
    int m;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .word = "998244353",
          .m = 3,
          .expected{1, 1, 0, 0, 0, 1, 1, 0, 0},
      },
      {
          .word = "1010",
          .m = 10,
          .expected{0, 1, 0, 1},
      },
  };

  for (const auto &[word, m, expected] : test_cases) {
    const auto actual = Solution::divisibilityArray(word, m);
    REQUIRE(expected == actual);
  }
}

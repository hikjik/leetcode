#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string dominoes;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .dominoes = ".L.R...LR..L..",
          .expected = "LL.RR.LLRRLL..",
      },
      {
          .dominoes = "RR.L",
          .expected = "RR.L",
      },
  };

  for (const auto &[dominoes, expected] : test_cases) {
    const auto actual = Solution::pushDominoes(dominoes);
    REQUIRE(expected == actual);
  }
}

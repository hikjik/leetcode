#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string startGene;
    std::string endGene;
    std::vector<std::string> bank;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .startGene = "AACCGGTT",
          .endGene = "AACCGGTA",
          .bank{"AACCGGTA"},
          .expected = 1,
      },
      {
          .startGene = "AACCGGTT",
          .endGene = "AAACGGTA",
          .bank{"AACCGGTA", "AACCGCTA", "AAACGGTA"},
          .expected = 2,
      },
  };

  for (const auto &[startGene, endGene, bank, expected] : test_cases) {
    const auto actual = Solution::minMutation(startGene, endGene, bank);
    REQUIRE(expected == actual);
  }
}

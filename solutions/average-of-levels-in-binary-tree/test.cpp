#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<double> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{3, 9, 20, std::nullopt, std::nullopt, 15, 7},
          .expected{3.00000, 14.50000, 11.00000},
      },
      {
          .root{3, 9, 20, 15, 7},
          .expected{3.00000, 14.50000, 11.00000},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::averageOfLevels(root);
    REQUIRE(expected == actual);
  }
}

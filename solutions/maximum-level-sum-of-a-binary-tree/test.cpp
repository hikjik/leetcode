#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, 7, 0, 7, -8, std::nullopt, std::nullopt},
          .expected = 2,
      },
      {
          .root{989, std::nullopt, 10250, 98693, -89388, std::nullopt,
                std::nullopt, std::nullopt, -32127},
          .expected = 2,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::maxLevelSum(root);
    REQUIRE(expected == actual);
  }
}

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
          .root = {8, 3, 10, 1, 6, std::nullopt, 14, std::nullopt, std::nullopt,
                   4, 7, 13},
          .expected = 7,
      },
      {
          .root = {1, std::nullopt, 2, std::nullopt, 0, 3},
          .expected = 3,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::maxAncestorDiff(root);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, 3, std::nullopt, std::nullopt, 2},
          .expected{3, 1, std::nullopt, std::nullopt, 2},
      },
      {
          .root{3, 1, 4, std::nullopt, std::nullopt, 2},
          .expected{2, 1, 4, std::nullopt, std::nullopt, 3},
      },
  };

  SECTION("Recursion") {
    for (const auto &[root, expected] : test_cases) {
      auto copy = Copy(root);
      recursion::Solution().recoverTree(copy);
      REQUIRE(expected == Tree(copy));
    }
  }

  SECTION("Iteration") {
    for (const auto &[root, expected] : test_cases) {
      auto copy = Copy(root);
      iteration::Solution::recoverTree(copy);
      REQUIRE(expected == Tree(copy));
    }
  }

  SECTION("Morris Traversal") {
    for (const auto &[root, expected] : test_cases) {
      auto copy = Copy(root);
      morris::Solution::recoverTree(copy);
      REQUIRE(expected == Tree(copy));
    }
  }
}

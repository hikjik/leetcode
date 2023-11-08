#include <catch.hpp>

#include <solution.hpp>

#include <tree_node_with_next.h>

#include <optional>
#include <queue>
#include <vector>

void CheckSolution(Node *root,
                   const std::vector<std::optional<int>> &expected) {
  std::vector<std::optional<int>> actual;
  for (auto node = root; node; node = node->left) {
    auto next = node;
    while (next) {
      actual.push_back(next->val);
      next = next->next;
    }
    actual.push_back(std::nullopt);
  }
  REQUIRE(expected == actual);
}

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<std::optional<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, 2, 3, 4, 5, 6, 7},
          .expected{1, std::nullopt, 2, 3, std::nullopt, 4, 5, 6, 7,
                    std::nullopt},
      },
      {
          .root{},
          .expected{},
      },
  };

  SECTION("Recursion") {
    for (auto &[root, expected] : test_cases) {
      CheckSolution(recursive::Solution::connect(root), expected);
    }
  }

  SECTION("Iterative") {
    for (auto &[root, expected] : test_cases) {
      CheckSolution(iterative::Solution::connect(root), expected);
    }
  }
}

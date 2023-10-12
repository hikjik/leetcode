#include <catch.hpp>

#include <solution.hpp>

#include <tree_node_with_next.h>

#include <optional>
#include <queue>
#include <vector>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<std::optional<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, 2, 3, 4, 5, std::nullopt, 7},
          .expected{1, std::nullopt, 2, 3, std::nullopt, 4, 5, 7, std::nullopt},
      },
      {
          .root{},
          .expected{},
      },
  };

  for (auto &[root, expected] : test_cases) {
    std::vector<std::optional<int>> actual;
    for (auto node = Solution::connect(root); node; node = node->left) {
      auto next = node;
      while (next) {
        actual.push_back(next->val);
        next = next->next;
      }
      actual.push_back(std::nullopt);
    }
    REQUIRE(expected == actual);
  }
}

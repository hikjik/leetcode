#include <catch.hpp>
#include <tree_node.h>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<int> &expected) {
  auto root = VectorToTree(values);

  REQUIRE(expected == Solution::postorderTraversal(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        1, std::nullopt, 2, std::nullopt, std::nullopt, 3};
    std::vector<int> expected{3, 2, 1};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{1};
    std::vector<int> expected{1};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values;
    std::vector<int> expected;
    CheckSolution(values, expected);
  }
}

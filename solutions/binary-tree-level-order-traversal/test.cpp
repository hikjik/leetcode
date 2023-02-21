#include <catch.hpp>
#include <tree_node.h>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::vector<int>> &expected) {
  auto root = VectorToTree(values);

  REQUIRE(expected == Solution::levelOrder(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    std::vector<std::vector<int>> expected{{3}, {9, 20}, {15, 7}};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{1};
    std::vector<std::vector<int>> expected{{1}};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values;
    std::vector<std::vector<int>> expected;
    CheckSolution(values, expected);
  }
}

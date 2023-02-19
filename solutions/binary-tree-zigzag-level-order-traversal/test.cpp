#include <catch.hpp>
#include <tree_node.h>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::vector<int>> &expected) {
  auto root = VectorToTree(values);

  REQUIRE(expected == Solution::zigzagLevelOrder(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values;
    std::vector<std::vector<int>> expected;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{
        3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    std::vector<std::vector<int>> expected{{3}, {20, 9}, {15, 7}};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{1};
    std::vector<std::vector<int>> expected{{1}};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{
        1, 2, 3, 4, std::nullopt, std::nullopt, 5};
    std::vector<std::vector<int>> expected{{1}, {3, 2}, {4, 5}};
    CheckSolution(values, expected);
  }
}

#include <catch.hpp>
#include <tree_node.h>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   bool expected) {
  auto root = VectorToTree(values);

  REQUIRE(expected == Solution::isBalanced(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    CheckSolution(values, true);
  }
  {
    std::vector<std::optional<int>> values{
        1, 2, 2, 3, 3, std::nullopt, std::nullopt, 4, 4};
    CheckSolution(values, false);
  }
  {
    std::vector<std::optional<int>> values;
    CheckSolution(values, true);
  }
}

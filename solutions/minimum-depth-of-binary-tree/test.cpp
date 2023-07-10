#include "tree_node.h"
#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::minDepth(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    int expected = 2;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{
        2, std::nullopt, 3, std::nullopt, 4, std::nullopt, 5, std::nullopt, 6};
    int expected = 5;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{5};
    int expected = 1;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values;
    int expected = 0;
    CheckSolution(values, expected);
  }
}

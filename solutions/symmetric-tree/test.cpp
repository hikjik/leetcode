#include <catch.hpp>
#include <tree_node.h>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   bool expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::isSymmetric(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, 2, 2, 3, 4, 4, 3};
    CheckSolution(values, true);
  }
  {
    std::vector<std::optional<int>> values{
        1, 2, 2, std::nullopt, 3, std::nullopt, 3};
    CheckSolution(values, false);
  }
}

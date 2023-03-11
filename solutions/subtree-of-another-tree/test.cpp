#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values_tree,
                   const std::vector<std::optional<int>> &values_sub_tree,
                   bool expected) {
  auto tree = VectorToTree(values_tree);
  auto sub_tree = VectorToTree(values_sub_tree);

  REQUIRE(expected == Solution::isSubtree(tree, sub_tree));

  FreeTree(tree);
  FreeTree(sub_tree);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values_tree{3, 4, 5, 1, 2};
    std::vector<std::optional<int>> values_sub_tree{4, 1, 2};
    bool expected = true;
    CheckSolution(values_tree, values_sub_tree, expected);
  }
  {
    std::vector<std::optional<int>> values_tree{
        3, 4, 5, 1, 2, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
        0};
    std::vector<std::optional<int>> values_sub_tree{4, 1, 2};
    bool expected = false;
    CheckSolution(values_tree, values_sub_tree, expected);
  }
}

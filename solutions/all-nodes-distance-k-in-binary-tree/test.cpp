#include "tree_node.h"
#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int target_value, int k, const std::vector<int> &expected) {
  auto root = VectorToTree(values);
  auto target = Find(root, target_value);
  REQUIRE(expected == Solution::distanceK(root, target, k));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4};
    int target_value = 5, k = 2;
    std::vector<int> expected{7, 4, 1};
    CheckSolution(values, target_value, k, expected);
  }
  {
    std::vector<std::optional<int>> values{1};
    int target_value = 1, k = 3;
    std::vector<int> expected;
    CheckSolution(values, target_value, k, expected);
  }
}

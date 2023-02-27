#include <catch.hpp>
#include <tree_node.h>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values, int target,
                   bool has_path) {
  auto root = VectorToTree(values);

  REQUIRE(has_path == Solution::hasPathSum(root, target));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int target = 22;
    bool has_path = true;
    std::vector<std::optional<int>> values{
        5, 4, 8, 11,           std::nullopt, 13,
        4, 7, 2, std::nullopt, std::nullopt, std::nullopt,
        1};
    CheckSolution(values, target, has_path);
  }
  {
    int target = 5;
    bool has_path = false;
    std::vector<std::optional<int>> values{1, 2, 3};
    CheckSolution(values, target, has_path);
  }
  {
    int target = 0;
    bool has_path = false;
    std::vector<std::optional<int>> values;
    CheckSolution(values, target, has_path);
  }
}

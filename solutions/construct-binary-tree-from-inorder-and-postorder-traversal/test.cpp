#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<int> &in_order,
                   const std::vector<int> &postorder,
                   const std::vector<std::optional<int>> &tree_values) {
  auto root_actual = Solution::buildTree(in_order, postorder);
  auto root_expected = VectorToTree(tree_values);

  REQUIRE(EqualTree(root_expected, root_actual));

  FreeTree(root_actual);
  FreeTree(root_expected);
}

TEST_CASE("Simple") {
  {
    std::vector<int> in_order{9, 3, 15, 20, 7};
    std::vector<int> postorder{9, 15, 7, 20, 3};
    std::vector<std::optional<int>> tree_values{
        3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    CheckSolution(in_order, postorder, tree_values);
  }
  {
    std::vector<int> in_order{-1};
    std::vector<int> postorder{-1};
    std::vector<std::optional<int>> tree_values{-1};
    CheckSolution(in_order, postorder, tree_values);
  }
}

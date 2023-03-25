#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values, int p_val,
                   int q_val, int lca_val) {
  auto root = VectorToTree(values);
  auto p = FindBST(root, p_val);
  auto q = FindBST(root, q_val);

  auto lca = Solution::lowestCommonAncestor(root, p, q);

  REQUIRE(lca);
  REQUIRE(lca_val == lca->val);

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5};
    int p = 2, q = 8;
    int lca = 6;
    CheckSolution(values, p, q, lca);
  }
}

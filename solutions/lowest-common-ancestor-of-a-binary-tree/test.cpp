#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values, int p_val,
                   int q_val, int expected) {
  auto root = VectorToTree(values);

  auto p = Find(root, p_val);
  auto q = Find(root, q_val);
  REQUIRE(p);
  REQUIRE(q);

  auto lca = Solution::lowestCommonAncestor(root, p, q);
  REQUIRE(lca);
  REQUIRE(expected == lca->val);

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4};
    int p_val = 5, q_val = 1;
    int expected = 3;
    CheckSolution(values, p_val, q_val, expected);
  }
  {
    std::vector<std::optional<int>> values{
        3, 5, 1, 6, 2, 0, 8, std::nullopt, std::nullopt, 7, 4};
    int p_val = 5, q_val = 4;
    int expected = 5;
    CheckSolution(values, p_val, q_val, expected);
  }
  {
    std::vector<std::optional<int>> values{1, 2};
    int p_val = 1, q_val = 2;
    int expected = 1;
    CheckSolution(values, p_val, q_val, expected);
  }
}

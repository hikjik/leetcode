#include <catch.hpp>

#include <solution.hpp>
#include <tree_node.hpp>

#include <optional>
#include <queue>
#include <vector>

TreeNode *VectorToTree(const std::vector<std::optional<int>> &values) {
  if (values.empty() || !values[0].has_value()) {
    return nullptr;
  }

  auto root = new TreeNode(values[0].value());
  std::queue<std::pair<TreeNode *, size_t>> items;
  items.emplace(root, 0);
  while (!items.empty()) {
    const auto &[node, index] = items.front();
    items.pop();

    const auto left = 2 * index + 1;
    if (left < values.size() && values[left].has_value()) {
      node->left = new TreeNode(values[left].value());
      items.emplace(node->left, left);
    }

    const auto right = 2 * index + 2;
    if (right < values.size() && values[right].has_value()) {
      node->right = new TreeNode(values[right].value());
      items.emplace(node->right, right);
    }
  }

  return root;
}

void FreeTree(TreeNode *root) {
  if (!root) {
    return;
  }

  FreeTree(root->left);
  FreeTree(root->right);
  delete root;
}

void CheckSolution(const std::vector<std::optional<int>> &values, int depth) {
  auto root = VectorToTree(values);

  REQUIRE(depth == Solution::maxDepth(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    CheckSolution(values, 3);
  }
  {
    std::vector<std::optional<int>> values{1, std::nullopt, 2};
    CheckSolution(values, 2);
  }
}

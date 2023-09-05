#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(int n,
                   const std::vector<std::vector<std::optional<int>>> &values) {
  std::vector<TreeNode *> expected;
  for (const auto &v : values) {
    expected.push_back(VectorToTree(v));
  }

  const auto actual = Solution().generateTrees(n);
  REQUIRE(expected.size() == actual.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    REQUIRE(EqualTree(expected[i], actual[i]));
  }

  for (auto &tree : expected) {
    FreeTree(tree);
  }
}

TEST_CASE("Simple") {
  {
    int n = 3;
    std::vector<std::vector<std::optional<int>>> values{
        {1, std::nullopt, 2, std::nullopt, 3},
        {1, std::nullopt, 3, 2},
        {2, 1, 3},
        {3, 1, std::nullopt, std::nullopt, 2},
        {3, 2, std::nullopt, 1}};
    CheckSolution(n, values);
  }
  {
    int n = 1;
    std::vector<std::vector<std::optional<int>>> values{{1}};
    CheckSolution(n, values);
  }
}

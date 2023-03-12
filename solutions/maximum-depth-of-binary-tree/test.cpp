#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

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

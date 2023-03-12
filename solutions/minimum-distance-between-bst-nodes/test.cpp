#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int max_diff) {
  auto root = VectorToTree(values);

  REQUIRE(max_diff == Solution::minDiffInBST(root));

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{4, 2, 6, 1, 3};
    CheckSolution(values, 1);
  }
  {
    std::vector<std::optional<int>> values{
        1, 0, 48, std::nullopt, std::nullopt, 12, 49};
    CheckSolution(values, 1);
  }
}

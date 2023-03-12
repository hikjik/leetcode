#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::vector<int>> &expected) {
  auto root = VectorToTree(values);

  const auto duplicates = Solution::findDuplicateSubtrees(root);
  std::vector<std::vector<int>> actual;
  for (auto &node : duplicates) {
    actual.push_back(TraversePreOrder(node));
  }

  REQUIRE(expected == actual);

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        1, 2, 3, 4, std::nullopt, 2, 4, std::nullopt, std::nullopt, 4};
    std::vector<std::vector<int>> expected{{4}, {2, 4}};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{2, 1, 1};
    std::vector<std::vector<int>> expected{{1}};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{2, 2,           2, 3, std::nullopt,
                                           3, std::nullopt};
    std::vector<std::vector<int>> expected{{3}, {2, 3}};
    CheckSolution(values, expected);
  }
}

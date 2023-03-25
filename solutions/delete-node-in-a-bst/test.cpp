#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values, int key,
                   const std::vector<int> &expected) {
  auto root = VectorToTree(values);
  auto root_after_delete = Solution::deleteNode(root, key);
  REQUIRE(expected == TraverseInOrder(root_after_delete));
  FreeTree(root_after_delete);
}

TEST_CASE("Simple") {
  {
    int key = 3;
    std::vector<std::optional<int>> values{5, 3, 6, 2, 4, std::nullopt, 7};
    std::vector<int> expected{2, 4, 5, 6, 7};
    CheckSolution(values, key, expected);
  }
  {
    int key = 0;
    std::vector<std::optional<int>> values{5, 3, 6, 2, 4, std::nullopt, 7};
    std::vector<int> expected{2, 3, 4, 5, 6, 7};
    CheckSolution(values, key, expected);
  }
  {
    int key = 0;
    std::vector<std::optional<int>> values;
    std::vector<int> expected;
    CheckSolution(values, key, expected);
  }
}

#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(const std::vector<int> &list_values,
                   const std::vector<std::optional<int>> &tree_values,
                   bool expected) {
  auto head = VectorToList(list_values);
  auto root = VectorToTree(tree_values);

  REQUIRE(expected == Solution::isSubPath(head, root));

  FreeList(head);
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<int> list_values{4, 2, 8};
    std::vector<std::optional<int>> tree_values{1,
                                                4,
                                                4,
                                                std::nullopt,
                                                2,
                                                2,
                                                std::nullopt,
                                                1,
                                                std::nullopt,
                                                6,
                                                8,
                                                std::nullopt,
                                                std::nullopt,
                                                std::nullopt,
                                                std::nullopt,
                                                1,
                                                3};
    bool expected = true;
    CheckSolution(list_values, tree_values, expected);
  }
  {
    std::vector<int> list_values{1, 4, 2, 6};
    std::vector<std::optional<int>> tree_values{1,
                                                4,
                                                4,
                                                std::nullopt,
                                                2,
                                                2,
                                                std::nullopt,
                                                1,
                                                std::nullopt,
                                                6,
                                                8,
                                                std::nullopt,
                                                std::nullopt,
                                                std::nullopt,
                                                std::nullopt,
                                                1,
                                                3};
    bool expected = true;
    CheckSolution(list_values, tree_values, expected);
  }
  {
    std::vector<int> list_values{1, 4, 2, 6, 8};
    std::vector<std::optional<int>> tree_values{1,
                                                4,
                                                4,
                                                std::nullopt,
                                                2,
                                                2,
                                                std::nullopt,
                                                1,
                                                std::nullopt,
                                                6,
                                                8,
                                                std::nullopt,
                                                std::nullopt,
                                                std::nullopt,
                                                std::nullopt,
                                                1,
                                                3};
    bool expected = false;
    CheckSolution(list_values, tree_values, expected);
  }
}

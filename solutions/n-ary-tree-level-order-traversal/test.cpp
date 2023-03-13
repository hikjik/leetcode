#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::vector<int>> &expected) {
  auto root = VectorToNAryTree(values);
  REQUIRE(expected == Solution::levelOrder(root));
  FreeNAryTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, std::nullopt, 3, 2,
                                           4, std::nullopt, 5, 6};
    std::vector<std::vector<int>> expected{{1}, {3, 2, 4}, {5, 6}};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{1,
                                           std::nullopt,
                                           2,
                                           3,
                                           4,
                                           5,
                                           std::nullopt,
                                           std::nullopt,
                                           6,
                                           7,
                                           std::nullopt,
                                           8,
                                           std::nullopt,
                                           9,
                                           10,
                                           std::nullopt,
                                           std::nullopt,
                                           11,
                                           std::nullopt,
                                           12,
                                           std::nullopt,
                                           13,
                                           std::nullopt,
                                           std::nullopt,
                                           14};
    std::vector<std::vector<int>> expected{
        {1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}};
    CheckSolution(values, expected);
  }
}

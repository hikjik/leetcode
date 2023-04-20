#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::widthOfBinaryTree(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int max_width = 4;
    std::vector<std::optional<int>> values{1, 3, 2, 5, 3, std::nullopt, 9};
    CheckSolution(values, max_width);
  }
  {
    int max_width = 7;
    std::vector<std::optional<int>> values{
        1, 3, 2, 5, std::nullopt, std::nullopt, 9, 6, std::nullopt, 7};
    CheckSolution(values, max_width);
  }
  {
    int max_width = 2;
    std::vector<std::optional<int>> values{1, 3, 2, 5};
    CheckSolution(values, max_width);
  }
}

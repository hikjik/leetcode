#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(const std::vector<std::vector<int>> &descriptions,
                   const std::vector<std::optional<int>> &values) {
  auto expected = VectorToTree(values);
  auto root = Solution::createBinaryTree(descriptions);
  REQUIRE(EqualTree(expected, root));
  FreeTree(expected);
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> descriptions{
        {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    std::vector<std::optional<int>> values{50, 20, 80, 15, 17, 19};
    CheckSolution(descriptions, values);
  }
  {
    std::vector<std::vector<int>> descriptions{{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
    std::vector<std::optional<int>> values{1, 2, std::nullopt, std::nullopt,
                                           3, 4};
    CheckSolution(descriptions, values);
  }
}

#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<int> &expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::rightSideView(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        1, 2, 3, std::nullopt, 5, std::nullopt, 4};
    std::vector<int> expected{1, 3, 4};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{1, std::nullopt, 3};
    std::vector<int> expected{1, 3};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values;
    std::vector<int> expected;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{
        1, 2, 3, std::nullopt, 5, 6, std::nullopt, 4};
    std::vector<int> expected{1, 3, 6, 4};
    CheckSolution(values, expected);
  }
}

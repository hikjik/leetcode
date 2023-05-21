#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<double> &expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::averageOfLevels(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{
        3, 9, 20, std::nullopt, std::nullopt, 15, 7};
    std::vector<double> expected{3.00000, 14.50000, 11.00000};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{3, 9, 20, 15, 7};
    std::vector<double> expected{3.00000, 14.50000, 11.00000};
    CheckSolution(values, expected);
  }
}

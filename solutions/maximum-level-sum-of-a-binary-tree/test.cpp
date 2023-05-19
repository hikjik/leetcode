#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::maxLevelSum(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int expected = 2;
    std::vector<std::optional<int>> values{
        1, 7, 0, 7, -8, std::nullopt, std::nullopt};
    CheckSolution(values, expected);
  }
  {
    int expected = 2;
    std::vector<std::optional<int>> values{
        989,          std::nullopt, 10250,        98693, -89388,
        std::nullopt, std::nullopt, std::nullopt, -32127};
    CheckSolution(values, expected);
  }
}

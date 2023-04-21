#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::maxPathSum(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int expected = 6;
    std::vector<std::optional<int>> values{1, 2, 3};
    CheckSolution(values, expected);
  }
  {
    int expected = 42;
    std::vector<std::optional<int>> values{-10,          9,  20, std::nullopt,
                                           std::nullopt, 15, 7};
    CheckSolution(values, expected);
  }
}

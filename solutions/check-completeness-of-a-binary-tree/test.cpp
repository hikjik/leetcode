#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   bool expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::isCompleteTree(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, 2, 3, 4, 5, 6};
    bool expected = true;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{1, 2, 3, 4, 5, std::nullopt, 7};
    bool expected = false;
    CheckSolution(values, expected);
  }
}

#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values1,
                   const std::vector<std::optional<int>> &values2,
                   const std::vector<std::optional<int>> &expected_values) {
  auto root1 = VectorToTree(values1);
  auto root2 = VectorToTree(values2);
  auto actual = Solution::mergeTrees(root1, root2);

  auto expected = VectorToTree(expected_values);
  REQUIRE(EqualTree(expected, actual));

  FreeTree(root1);
  FreeTree(root2);
  FreeTree(expected);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values1{1, 3, 2, 5};
    std::vector<std::optional<int>> values2{
        2, 1, 3, std::nullopt, 4, std::nullopt, 7};
    std::vector<std::optional<int>> expected{3, 4, 5, 5, 4, std::nullopt, 7};
    CheckSolution(values1, values2, expected);
  }
  {
    std::vector<std::optional<int>> values1{1};
    std::vector<std::optional<int>> values2{1, 2};
    std::vector<std::optional<int>> expected{2, 2};
    CheckSolution(values1, values2, expected);
  }
}

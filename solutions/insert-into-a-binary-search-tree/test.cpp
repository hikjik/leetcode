#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::optional<int>> &values_expected,
                   int target) {
  auto root = VectorToTree(values);
  auto actual = Solution::insertIntoBST(root, target);

  auto expected = VectorToTree(values_expected);

  REQUIRE(EqualTree(actual, expected));

  FreeTree(actual);
  FreeTree(expected);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{4, 2, 7, 1, 3};
    std::vector<std::optional<int>> expected{4, 2, 7, 1, 3, 5};
    int target = 5;
    CheckSolution(values, expected, target);
  }
  {
    std::vector<std::optional<int>> values{40, 20, 60, 10, 30, 50, 70};
    std::vector<std::optional<int>> expected{
        40, 20, 60, 10, 30, 50, 70, std::nullopt, std::nullopt, 25};
    int target = 25;
    CheckSolution(values, expected, target);
  }
}

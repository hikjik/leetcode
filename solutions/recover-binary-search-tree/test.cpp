#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::optional<int>> &expected) {
  auto root = VectorToTree(values);
  Solution().recoverTree(root);
  auto expected_root = VectorToTree(expected);

  REQUIRE(EqualTree(root, expected_root));

  FreeTree(root);
  FreeTree(expected_root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, 3, std::nullopt, std::nullopt, 2};
    std::vector<std::optional<int>> expected{3, 1, std::nullopt, std::nullopt,
                                             2};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{3, 1, 4, std::nullopt, std::nullopt,
                                           2};
    std::vector<std::optional<int>> expected{
        2, 1, 4, std::nullopt, std::nullopt, 3};
    CheckSolution(values, expected);
  }
}

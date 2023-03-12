#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <queue>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::optional<int>> &expected) {
  auto root = VectorToTree(values);
  Solution::connect(root);

  std::vector<std::optional<int>> actual;
  for (auto node = root; node; node = node->left) {
    auto next = node;
    while (next) {
      actual.push_back(next->val);
      next = next->next;
    }
    actual.push_back(std::nullopt);
  }

  REQUIRE(expected == actual);

  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{1, 2, 3, 4, 5, std::nullopt, 7};
    std::vector<std::optional<int>> expected{
        1, std::nullopt, 2, 3, std::nullopt, 4, 5, 7, std::nullopt};
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values;
    std::vector<std::optional<int>> expected;
    CheckSolution(values, expected);
  }
  {
    std::vector<std::optional<int>> values{
        1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, std::nullopt, std::nullopt,
        5, 5};
    std::vector<std::optional<int>> expected{1,
                                             std::nullopt,
                                             2,
                                             2,
                                             std::nullopt,
                                             3,
                                             3,
                                             3,
                                             3,
                                             std::nullopt,
                                             4,
                                             4,
                                             4,
                                             4,
                                             4,
                                             4,
                                             std::nullopt,
                                             5,
                                             5,
                                             std::nullopt};
    CheckSolution(values, expected);
  }
}

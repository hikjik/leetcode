#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   int expected) {
  auto root = VectorToTree(values);
  REQUIRE(expected == Solution::longestZigZag(root));
  FreeTree(root);
}

TEST_CASE("Simple") {
  {
    int expected = 3;
    std::vector<std::optional<int>> values{1,
                                           std::nullopt,
                                           1,
                                           1,
                                           1,
                                           std::nullopt,
                                           std::nullopt,
                                           1,
                                           1,
                                           std::nullopt,
                                           1,
                                           std::nullopt,
                                           std::nullopt,
                                           std::nullopt,
                                           1,
                                           std::nullopt,
                                           1};
    CheckSolution(values, expected);
  }
  {
    int expected = 4;
    std::vector<std::optional<int>> values{1,
                                           1,
                                           1,
                                           std::nullopt,
                                           1,
                                           std::nullopt,
                                           std::nullopt,
                                           1,
                                           1,
                                           std::nullopt,
                                           1};
    CheckSolution(values, expected);
  }
  {
    int expected = 0;
    std::vector<std::optional<int>> values{1};
    CheckSolution(values, expected);
  }
}

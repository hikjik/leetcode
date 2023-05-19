#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(const std::vector<std::optional<int>> &values1,
                   const std::vector<std::optional<int>> &values2,
                   bool expected) {
  auto root1 = VectorToTree(values1);
  auto root2 = VectorToTree(values2);
  REQUIRE(expected == Solution::leafSimilar(root1, root2));
  FreeTree(root1);
  FreeTree(root2);
}

TEST_CASE("Simple") {
  {
    bool expected = true;
    std::vector<std::optional<int>> values1{
        3, 5, 1, 6, 2, 9, 8, std::nullopt, std::nullopt, 7, 4};
    std::vector<std::optional<int>> values2{3,
                                            5,
                                            1,
                                            6,
                                            7,
                                            4,
                                            2,
                                            std::nullopt,
                                            std::nullopt,
                                            std::nullopt,
                                            std::nullopt,
                                            std::nullopt,
                                            std::nullopt,
                                            9,
                                            8};
    CheckSolution(values1, values2, expected);
  }
  {
    bool expected = false;
    std::vector<std::optional<int>> values1{1, 2, 3};
    std::vector<std::optional<int>> values2{1, 3, 2};
    CheckSolution(values1, values2, expected);
  }
}

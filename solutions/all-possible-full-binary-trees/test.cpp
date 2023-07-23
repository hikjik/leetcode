#include <catch.hpp>

#include <solution.hpp>

#include <optional>

void CheckSolution(int n,
                   std::vector<std::vector<std::optional<int>>> expected) {
  auto actual = Solution::allPossibleFBT(n);
  REQUIRE(actual.size() == expected.size());
  for (size_t i = 0; i < actual.size(); ++i) {
    auto tree = VectorToTree(expected[i]);
    REQUIRE(EqualTree(tree, actual[i]));
    FreeTree(tree);
  }
}

TEST_CASE("Simple") {
  {
    int n = 7;
    std::vector<std::vector<std::optional<int>>> expected{
        {0, 0, 0, std::nullopt, std::nullopt, 0, 0, std::nullopt, std::nullopt,
         0, 0},
        {0, 0, 0, std::nullopt, std::nullopt, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
         0, 0},
        {0, 0, 0, 0, 0, std::nullopt, std::nullopt, 0, 0}};
    CheckSolution(n, expected);
  }
  {
    int n = 3;
    std::vector<std::vector<std::optional<int>>> expected{{0, 0, 0}};
    CheckSolution(n, expected);
  }
  {
    int n = 2;
    std::vector<std::vector<std::optional<int>>> expected;
    CheckSolution(n, expected);
  }
}

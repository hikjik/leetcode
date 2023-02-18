#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::vector<std::optional<int>> &values,
                   const std::vector<std::optional<int>> &inverted) {
  auto actual = Solution::invertTree(VectorToTree(values));
  auto expected = VectorToTree(inverted);

  REQUIRE(EqualTree(expected, actual));

  FreeTree(actual);
  FreeTree(expected);
}

TEST_CASE("Simple") {
  {
    std::vector<std::optional<int>> values{4, 2, 7, 1, 3, 6, 9};
    std::vector<std::optional<int>> inverted{4, 7, 2, 9, 6, 3, 1};
    CheckSolution(values, inverted);
  }
  {
    std::vector<std::optional<int>> values{2, 1, 3};
    std::vector<std::optional<int>> inverted{2, 3, 1};
    CheckSolution(values, inverted);
  }
  {
    std::vector<std::optional<int>> values;
    std::vector<std::optional<int>> inverted;
    CheckSolution(values, inverted);
  }
}

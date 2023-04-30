#include <catch.hpp>

#include <solution.hpp>

#include <optional>
#include <vector>

void CheckSolution(const std::string &traversal,
                   const std::vector<std::optional<int>> &values) {
  auto actual = Solution::recoverFromPreorder(traversal);
  auto expected = VectorToTree(values);
  REQUIRE(EqualTree(expected, actual));
  FreeTree(expected), FreeTree(actual);
}

TEST_CASE("Simple") {
  {
    std::string traversal = "1-2--3--4-5--6--7";
    std::vector<std::optional<int>> values{1, 2, 5, 3, 4, 6, 7};
    CheckSolution(traversal, values);
  }
  {
    std::string traversal = "1-2--3---4-5--6---7";
    std::vector<std::optional<int>> values{
        1, 2, 5, 3, std::nullopt, 6, std::nullopt, 4, std::nullopt, 7};
    CheckSolution(traversal, values);
  }
  {
    std::string traversal = "1-401--349---90--88";
    std::vector<std::optional<int>> values{1, 401, std::nullopt, 349, 88, 90};
    CheckSolution(traversal, values);
  }
}

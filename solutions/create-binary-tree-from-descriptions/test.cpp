#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> descriptions;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .descriptions{
              {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}},
          .expected{50, 20, 80, 15, 17, 19},
      },
      {
          .descriptions{{1, 2, 1}, {2, 3, 0}, {3, 4, 1}},
          .expected{1, 2, std::nullopt, std::nullopt, 3, 4},
      },
  };

  for (const auto &[descriptions, expected] : test_cases) {
    const Tree actual = Solution::createBinaryTree(descriptions);
    REQUIRE(expected == actual);
  }
}

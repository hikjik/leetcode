#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int val;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {4, 1, 3, std::nullopt, std::nullopt, 2},
          .val = 5,
          .expected = {5, 4, std::nullopt, 1, 3, std::nullopt, std::nullopt, 2},
      },
      {
          .root = {5, 2, 4, std::nullopt, 1},
          .val = 3,
          .expected = {5, 2, 4, std::nullopt, 1, std::nullopt, 3},
      },
      {
          .root = {5, 2, 3, std::nullopt, 1},
          .val = 4,
          .expected = {5, 2, 4, std::nullopt, 1, 3},
      },
  };

  for (const auto &[root, val, expected] : test_cases) {
    const Tree actual = Solution::insertIntoMaxTree(Copy(root), val);
    REQUIRE(expected == actual);
  }
}

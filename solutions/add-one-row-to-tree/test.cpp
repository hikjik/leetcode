#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int val;
    int depth;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {4, 2, 6, 3, 1, 5},
          .val = 1,
          .depth = 2,
          .expected = {4, 1, 1, 2, std::nullopt, std::nullopt, 6, 3, 1, 5},
      },
      {
          .root = {4, 2, std::nullopt, 3, 1},
          .val = 1,
          .depth = 3,
          .expected = {4, 2, std::nullopt, 1, 1, 3, std::nullopt, std::nullopt,
                       1},
      },
      {
          .root = {5},
          .val = 1,
          .depth = 1,
          .expected = {1, 5},
      },
      {
          .root = {1, 2, 3, 4},
          .val = 5,
          .depth = 4,
          .expected = {1, 2, 3, 4, std::nullopt, std::nullopt, std::nullopt, 5,
                       5},
      },
  };

  for (const auto &[root, val, depth, expected] : test_cases) {
    const Tree actual = Solution::addOneRow(Copy(root), val, depth);
    REQUIRE(expected == actual);
  }
}

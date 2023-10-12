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
          .root{4, 2, 7, 1, 3},
          .val = 5,
          .expected{4, 2, 7, 1, 3, 5},
      },
      {
          .root{40, 20, 60, 10, 30, 50, 70},
          .val = 25,
          .expected{40, 20, 60, 10, 30, 50, 70, std::nullopt, std::nullopt, 25},
      },
      {
          .root{4, 2, 7, 1, 3, std::nullopt, std::nullopt, std::nullopt,
                std::nullopt, std::nullopt, std::nullopt},
          .val = 5,
          .expected{4, 2, 7, 1, 3, 5},
      },
  };

  for (const auto &[root, val, expected] : test_cases) {
    const Tree actual = Solution::insertIntoBST(Copy(root), val);
    REQUIRE(expected == actual);
  }
}

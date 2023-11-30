#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> preorder;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .preorder{4, 2},
          .expected = {4, 2},
      },
      {
          .preorder{8, 5, 1, 7, 10, 12},
          .expected = {8, 5, 10, 1, 7, std::nullopt, 12},
      },
      {
          .preorder{1, 3},
          .expected = {1, std::nullopt, 3},
      },
  };

  SECTION("Recursion + Binary Search") {
    for (const auto &[preorder, expected] : test_cases) {
      const Tree actual = bs::Solution::bstFromPreorder(preorder);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Recursion Linear Time") {
    for (const auto &[preorder, expected] : test_cases) {
      const Tree actual = linear::Solution::bstFromPreorder(preorder);
      REQUIRE(expected == actual);
    }
  }
}

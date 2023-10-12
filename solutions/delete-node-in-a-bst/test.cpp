#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int key;
    Tree expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{5, 3, 6, 2, 4, std::nullopt, 7},
          .key = 3,
          .expected{5, 4, 6, 2, std::nullopt, std::nullopt, 7},
      },
      {
          .root{5, 3, 6, 2, 4, std::nullopt, 7},
          .key = 0,
          .expected{5, 3, 6, 2, 4, std::nullopt, 7},
      },
      {
          .root{},
          .key = 0,
          .expected{},
      },
  };

  for (const auto &[root, key, expected] : test_cases) {
    const Tree actual = Solution::deleteNode(Copy(root), key);
    REQUIRE(expected == actual);
  }
}

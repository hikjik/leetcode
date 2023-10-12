#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<Tree> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, 2, 3, 4, std::nullopt, 2, 4, std::nullopt, std::nullopt, 4},
          .expected{{4}, {2, 4}},
      },
      {
          .root{2, 1, 1},
          .expected{{1}},
      },
      {
          .root{2, 2, 2, 3, std::nullopt, 3, std::nullopt},
          .expected{{3}, {2, 3}},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::findDuplicateSubtrees(root);

    REQUIRE(expected.size() == actual.size());
    for (size_t i = 0; i < expected.size(); ++i) {
      REQUIRE(expected[i] == Tree(Copy(actual[i])));
    }
  }
}

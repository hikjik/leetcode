#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int target;
    std::vector<Tree> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {4, 2, 6, 1, 3, 5, 7},
          .target = 2,
          .expected{{2, 1}, {4, 3, 6, std::nullopt, std::nullopt, 5, 7}},
      },
      {
          .root = {1},
          .target = 1,
          .expected{{1}, {}},
      },
  };

  for (const auto &[root, target, expected] : test_cases) {
    const auto actual = Solution::splitBST(Copy(root), target);
    REQUIRE(expected.size() == actual.size());
    for (int i = 0; i < std::ssize(expected); ++i) {
      REQUIRE(expected[i] == Tree(actual[i]));
    }
  }
}

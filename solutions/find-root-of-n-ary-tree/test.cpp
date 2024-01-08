#include <catch.hpp>

#include <node.h>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    Tree tree;
  };

  std::vector<TestCase> test_cases{
      {
          .tree = {1, std::nullopt, 3, 2, 4, std::nullopt, 5, 6},
      },
      {
          .tree = {1,
                   std::nullopt,
                   2,
                   3,
                   4,
                   5,
                   std::nullopt,
                   std::nullopt,
                   6,
                   7,
                   std::nullopt,
                   8,
                   std::nullopt,
                   9,
                   10,
                   std::nullopt,
                   std::nullopt,
                   11,
                   std::nullopt,
                   12,
                   std::nullopt,
                   13,
                   std::nullopt,
                   std::nullopt,
                   14},
      },
  };

  for (const auto &[tree] : test_cases) {
    std::vector<Node *> nodes{tree};
    for (int i = 0; i < std::ssize(nodes);) {
      const int sz = nodes.size();
      for (int j = i; j < sz; ++j) {
        std::ranges::copy(nodes[j]->children, std::back_inserter(nodes));
      }
      i = sz;
    }

    const auto actual = Solution::findRoot(nodes);
    REQUIRE(tree.Root() == actual);
  }
}

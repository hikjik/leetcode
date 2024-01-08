#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {1, 2, 3, 4, 5},
          .expected{{4, 5, 3}, {2}, {1}},
      },
      {
          .root = {1},
          .expected{{1}},
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::findLeaves(root);
    REQUIRE(expected.size() == actual.size());
    for (size_t i = 0; i < actual.size(); ++i) {
      REQUIRE_THAT(expected[i], Catch::Matchers::UnorderedEquals(actual[i]));
    }
  }
}

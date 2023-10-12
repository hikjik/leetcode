#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root{1, std::nullopt, 1, 1, 1, std::nullopt, std::nullopt, 1, 1,
                std::nullopt, 1, std::nullopt, std::nullopt, std::nullopt, 1},
          .expected = 3,
      },
      {
          .root{1, 1, 1, std::nullopt, 1, std::nullopt, std::nullopt, 1, 1,
                std::nullopt, 1},
          .expected = 4,
      },
      {
          .root{1},
          .expected = 0,
      },
  };

  for (const auto &[root, expected] : test_cases) {
    const auto actual = Solution::longestZigZag(root);
    REQUIRE(expected == actual);
  }
}

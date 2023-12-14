#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root1;
    Tree root2;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root1 = {1, 2, 3, 4, 5, 6, std::nullopt, std::nullopt, std::nullopt,
                    7, 8},
          .root2 = {1, 3, 2, std::nullopt, 6, 4, 5, std::nullopt, std::nullopt,
                    std::nullopt, std::nullopt, 8, 7},
          .expected = true,
      },
      {
          .root1 = {},
          .root2 = {},
          .expected = true,
      },
      {
          .root1 = {},
          .root2 = {1},
          .expected = false,
      },
  };

  for (const auto &[root1, root2, expected] : test_cases) {
    const auto actual = Solution::flipEquiv(root1, root2);
    REQUIRE(expected == actual);
  }
}

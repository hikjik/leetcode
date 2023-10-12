#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>
#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    Tree root;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{4, 2, 8},
          .root{1, 4, 4, std::nullopt, 2, 2, std::nullopt, 1, std::nullopt, 6,
                8, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 1,
                3},
          .expected = true,
      },
      {
          .head{1, 4, 2, 6},
          .root{1, 4, 4, std::nullopt, 2, 2, std::nullopt, 1, std::nullopt, 6,
                8, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 1,
                3},
          .expected = true,
      },
      {
          .head{1, 4, 2, 6, 8},
          .root{1, 4, 4, std::nullopt, 2, 2, std::nullopt, 1, std::nullopt, 6,
                8, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 1,
                3},
          .expected = false,
      },
  };

  for (const auto &[head, root, expected] : test_cases) {
    const auto actual = Solution::isSubPath(head, root);
    REQUIRE(expected == actual);
  }
}

#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree p;
    Tree q;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .p{1, 2, 3},
          .q{1, 2, 3},
          .expected = true,
      },
      {
          .p{1, 2},
          .q{1, std::nullopt, 2},
          .expected = false,
      },
      {
          .p{1, 2, 1},
          .q{1, 1, 2},
          .expected = false,
      },
  };

  for (const auto &[p, q, expected] : test_cases) {
    const auto actual = Solution::isSameTree(p, q);
    REQUIRE(expected == actual);
  }
}

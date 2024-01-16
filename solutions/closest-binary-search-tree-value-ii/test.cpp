#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    double target;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {4, 2, 5, 1, 3},
          .target = 3.714286,
          .k = 2,
          .expected{4, 3},
      },
      {
          .root = {1},
          .target = 0.000000,
          .k = 1,
          .expected{1},
      },
  };

  for (const auto &[root, target, k, expected] : test_cases) {
    const auto actual = Solution::closestKValues(root, target, k);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}

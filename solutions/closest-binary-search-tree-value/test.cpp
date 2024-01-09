#include <catch.hpp>

#include <solution.hpp>

#include <tree_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    Tree root;
    double target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .root = {4, 2, 5, 1, 3},
          .target = 3.714286,
          .expected = 4,
      },
      {
          .root = {1},
          .target = 4.428571,
          .expected = 1,
      },
  };

  for (const auto &[root, target, expected] : test_cases) {
    const auto actual = Solution::closestValue(root, target);
    REQUIRE(expected == actual);
  }
}

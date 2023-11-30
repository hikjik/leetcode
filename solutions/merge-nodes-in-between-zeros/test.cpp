#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head = {0, 3, 1, 0, 4, 5, 2, 0},
          .expected = {4, 11},
      },
      {
          .head = {0, 1, 0, 3, 0, 2, 2, 0},
          .expected = {1, 3, 4},
      },
      {
          .head = {0, 14, 13, 0, 40, 0},
          .expected = {27, 40},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::mergeNodes(Copy(head));
    REQUIRE(expected == actual);
  }
}

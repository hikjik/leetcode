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
          .head = {5, 2, 13, 3, 8},
          .expected = {13, 8},
      },
      {
          .head = {1, 1, 1, 1},
          .expected = {1, 1, 1, 1},
      },
  };

  SECTION("Recursion") {
    for (const auto &[head, expected] : test_cases) {
      const List actual = recursion::Solution::removeNodes(Copy(head));
      REQUIRE(expected == actual);
    }
  }

  SECTION("Stack") {
    for (const auto &[head, expected] : test_cases) {
      const List actual = stack::Solution::removeNodes(Copy(head));
      REQUIRE(expected == actual);
    }
  }
}

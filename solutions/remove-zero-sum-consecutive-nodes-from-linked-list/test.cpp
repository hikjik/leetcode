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
          .head = {1, 2, -3, 3, 1},
          .expected = {3, 1},
      },
      {
          .head = {1, 2, 3, -3, 4},
          .expected = {1, 2, 4},
      },
      {
          .head = {1, 2, 3, -3, -2},
          .expected = {1},
      },
  };

  SECTION("Prefix Sum") {
    for (const auto &[head, expected] : test_cases) {
      const List actual = ps::Solution::removeZeroSumSublists(Copy(head));
      REQUIRE(expected == actual);
    }
  }

  SECTION("Hash Table") {
    for (const auto &[head, expected] : test_cases) {
      const List actual = ht::Solution::removeZeroSumSublists(Copy(head));
      REQUIRE(expected == actual);
    }
  }
}

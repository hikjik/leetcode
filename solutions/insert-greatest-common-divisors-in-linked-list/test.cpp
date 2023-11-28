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
          .head = {18, 6, 10, 3},
          .expected = {18, 6, 6, 2, 10, 1, 3},
      },
      {
          .head = {7},
          .expected = {7},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::insertGreatestCommonDivisors(Copy(head));
    REQUIRE(expected == actual);
  }
}

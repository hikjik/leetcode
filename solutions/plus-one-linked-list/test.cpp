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
          .head = {1, 2, 3},
          .expected = {1, 2, 4},
      },
      {
          .head = {0},
          .expected = {1},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::plusOne(Copy(head));
    REQUIRE(expected == actual);
  }
}

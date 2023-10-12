#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 0, 1},
          .expected = 5,
      },
      {
          .head{0},
          .expected = 0,
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const auto actual = Solution::getDecimalValue(head);
    REQUIRE(expected == actual);
  }
}

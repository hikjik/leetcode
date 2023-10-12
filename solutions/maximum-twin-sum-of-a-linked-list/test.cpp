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
          .head{5, 4, 2, 1},
          .expected = 6,
      },
      {
          .head{4, 2, 2, 3},
          .expected = 7,
      },
      {
          .head{1, 100000},
          .expected = 100001,
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const auto actual = Solution::pairSum(head);
    REQUIRE(expected == actual);
  }
}

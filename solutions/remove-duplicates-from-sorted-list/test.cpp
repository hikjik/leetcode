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
          .head{1, 1, 2},
          .expected{1, 2},
      },
      {
          .head{1, 1, 2, 3, 3},
          .expected{1, 2, 3},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::deleteDuplicates(Copy(head));
    REQUIRE(expected == actual);
  }
}

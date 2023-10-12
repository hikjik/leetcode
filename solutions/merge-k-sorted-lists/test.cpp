#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<List> lists;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .lists{{1, 4, 5}, {1, 3, 4}, {2, 6}},
          .expected{1, 1, 2, 3, 4, 4, 5, 6},
      },
      {
          .lists{},
          .expected{},
      },
      {
          .lists{{}},
          .expected{},
      },
  };

  for (const auto &[lists, expected] : test_cases) {
    const List actual = Solution::mergeKLists({lists.begin(), lists.end()});
    REQUIRE(expected == actual);
  }
}

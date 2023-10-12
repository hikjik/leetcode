#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    int k;
    std::vector<List> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{1, 2, 3},
          .k = 5,
          .expected{{1}, {2}, {3}, {}, {}},
      },
      {
          .head{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
          .k = 3,
          .expected{{1, 2, 3, 4}, {5, 6, 7}, {8, 9, 10}},
      },
  };

  for (const auto &[head, k, expected] : test_cases) {
    const auto actual = Solution::splitListToParts(Copy(head), k);
    REQUIRE(expected.size() == actual.size());
    for (size_t i = 0; i < expected.size(); ++i) {
      REQUIRE(expected[i] == List(actual[i]));
    }
  }
}

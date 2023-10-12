#include <catch.hpp>

#include <solution.hpp>

#include <list_node_with_random.h>

TEST_CASE("Simple") {
  struct TestCase {
    List head;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .head{{7, std::nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}},
          .expected{{7, std::nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}},
      },
      {
          .head{{1, 1}, {2, 1}},
          .expected{{1, 1}, {2, 1}},
      },
      {
          .head{{3, std::nullopt}, {3, 0}, {3, std::nullopt}},
          .expected{{3, std::nullopt}, {3, 0}, {3, std::nullopt}},
      },
  };

  for (const auto &[head, expected] : test_cases) {
    const List actual = Solution::copyRandomList(head);
    REQUIRE(expected == actual);
  }
}

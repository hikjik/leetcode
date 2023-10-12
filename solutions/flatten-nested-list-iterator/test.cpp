#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<NestedInteger> nestedList;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nestedList{{1, 1}, 2, {1, 1}},
          .expected{1, 1, 2, 1, 1},
      },
      {
          .nestedList{1, {4, {6}}},
          .expected{1, 4, 6},
      },
  };

  for (const auto &[nestedList, expected] : test_cases) {
    NestedIterator iterator(nestedList);
    std::vector<int> flatten;
    while (iterator.hasNext()) {
      flatten.push_back(iterator.next());
    }
    REQUIRE(expected == flatten);
  }
}

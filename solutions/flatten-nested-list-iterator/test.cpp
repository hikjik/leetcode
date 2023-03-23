#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(const std::vector<NestedInteger> &nested_list,
                   const std::vector<int> expected) {
  NestedIterator iterator(nested_list);
  std::vector<int> flatten;
  while (iterator.hasNext()) {
    flatten.push_back(iterator.next());
  }
  REQUIRE(expected == flatten);
}

TEST_CASE("Simple") {
  {
    std::vector<NestedInteger> list{{NestedInteger(1), NestedInteger(1)},
                                    NestedInteger(2),
                                    {NestedInteger(1), NestedInteger(1)}};
    std::vector<int> expected{1, 1, 2, 1, 1};
    CheckSolution(list, expected);
  }
  {
    std::vector<NestedInteger> list{NestedInteger(1),
                                    {NestedInteger(4), {NestedInteger(6)}}};
    std::vector<int> expected{1, 4, 6};
    CheckSolution(list, expected);
  }
  {
    std::vector<NestedInteger> list{{}};
    std::vector<int> expected;
    CheckSolution(list, expected);
  }
}

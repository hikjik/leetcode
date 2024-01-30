#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<NestedInteger> nestedList;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nestedList{{1, 1}, 2, {1, 1}},
          .expected = 10,
      },
      {
          .nestedList{1, {4, {6}}},
          .expected = 27,
      },
      {
          .nestedList{0},
          .expected = 0,
      },
  };

  for (const auto &[nestedList, expected] : test_cases) {
    const auto actual = Solution::depthSum(nestedList);
    REQUIRE(expected == actual);
  }
}

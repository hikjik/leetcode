#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> firstList;
    std::vector<std::vector<int>> secondList;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .firstList{{0, 2}, {5, 10}, {13, 23}, {24, 25}},
          .secondList{{1, 5}, {8, 12}, {15, 24}, {25, 26}},
          .expected{{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}},
      },
      {
          .firstList{{1, 3}, {5, 9}},
          .secondList{},
          .expected{},
      },
  };

  for (const auto &[firstList, secondList, expected] : test_cases) {
    const auto actual = Solution::intervalIntersection(firstList, secondList);
    REQUIRE(expected == actual);
  }
}

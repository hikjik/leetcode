#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> items1;
    std::vector<std::vector<int>> items2;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .items1{{1, 1}, {4, 5}, {3, 8}},
          .items2{{3, 1}, {1, 5}},
          .expected{{1, 6}, {3, 9}, {4, 5}},
      },
      {
          .items1{{1, 1}, {3, 2}, {2, 3}},
          .items2{{2, 1}, {3, 2}, {1, 3}},
          .expected{{1, 4}, {2, 4}, {3, 4}},
      },
      {
          .items1{{1, 3}, {2, 2}},
          .items2{{7, 1}, {2, 2}, {1, 4}},
          .expected{{1, 7}, {2, 4}, {7, 1}},
      },
  };

  for (const auto &[items1, items2, expected] : test_cases) {
    const auto actual = Solution::mergeSimilarItems(items1, items2);
    REQUIRE(expected == actual);
  }
}
